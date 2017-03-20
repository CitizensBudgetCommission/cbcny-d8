<?php

namespace Drupal\migrate_cbc\plugin\migrate\source;

use Drupal\migrate\Plugin\MigrationPluginManagerInterface;
use Drupal\migrate\Plugin\MigrationInterface;
use Drupal\migrate\Row;
use Drupal\node\Plugin\migrate\source\d6\Node;
use Symfony\Component\DependencyInjection\ContainerInterface;
use Drupal\Core\Entity\EntityManagerInterface;
use Drupal\Core\Extension\ModuleHandler;
use Drupal\Core\State\StateInterface;


/**
 * Drupal 6 node source from database.
 * - Splits body and attached files into paragraphs.
 * - Includes migration plugin manager so we can look up destination IDs from previous migrations
 *
 * @MigrateSource(
 *   id = "cbc_d6_node"
 * )
 */
class CbcNode extends Node
{

    /**
     * The migration plugin manager.
     *
     * @var \Drupal\migrate\Plugin\MigrationPluginManagerInterface
     */
    protected $migrationPluginManager;

    /**
     * The module handler.
     *
     * @var \Drupal\Core\Extension\ModuleHandler
     */

    protected $moduleHandler;


    /**
     * @inheritdoc
     */
    public function __construct(array $configuration, $plugin_id, $plugin_definition, MigrationInterface $migration, StateInterface $state,
                                EntityManagerInterface $entity_manager, MigrationPluginManagerInterface $migration_plugin_manager, ModuleHandler $module_handler)
    {
        parent::__construct($configuration, $plugin_id, $plugin_definition, $migration, $state, $entity_manager, $module_handler);
        $this->moduleHandler = $module_handler;
        $this->migrationPluginManager = $migration_plugin_manager;
    }

    /**
     * @inheritdoc
     */
    public static function create(ContainerInterface $container, array $configuration, $plugin_id, $plugin_definition, MigrationInterface $migration = NULL)
    {
        return new static(
            $configuration,
            $plugin_id,
            $plugin_definition,
            $migration,
            $container->get('state'),
            $container->get('entity.manager'),
            $container->get('plugin.manager.migration'),
            $container->get('module_handler')
        );
    }

    /**
     * @inheritdoc
     */
    public function fields()
    {
        return parent::fields() + [
            'paragraphs' => $this->t('Computed paragraph IDs for the body field.')
        ];
    }

    /**
     * @inheritdoc
     */
    public function prepareRow(Row $row)
    {
        // Add the paragraphs field.
        $this->getParagraphs($row);

        return parent::prepareRow($row);
    }

    /**
     * Add the paragraphs field with appropriate values.
     *
     * It really really seems like there should be a way to do this from inside the yml,
     * but there's no way (I could find) to handle overlapping source IDs *and* remove
     * NULL destinations from the final array. (entity_reference_revisions blows up with
     * a null value). So here it is, in the source plugin.
     *
     * @param \Drupal\migrate\Row $row
     */
    private function getParagraphs(Row $row)
    {
        // Get paragraphs.
        $paragraphs = array_merge(
        // full_text paragraph for body text.
            $this->lookupDestinationId('d6_node_paragraph_text', $row->getSourceProperty('nid')),
            // download_callout paragraph for files.
            $this->lookupDestinationId('d6_node_paragraph_files', $row->getSourceProperty('vid'))
        );

        // Set the value on the row, removing null members while we're at it.
        $row->setSourceProperty('paragraphs', array_filter($paragraphs));
    }

    /**
     * Look up the destination ID from a source ID value in a named migration.
     *
     * @param string $migration_id
     * @param $source_id
     * @return array of destination IDs from this map.
     */
    private function lookupDestinationId(string $migration_id, $source_id)
    {

        // Catch empty values
        if (empty($source_id) || empty($migration_id)) {
            return [];
        }
        // Get the d6_node_paragraph_text migration.
        $migration = $this->migrationPluginManager->createInstance($migration_id);
        // Look up the destination paragraph ID based on our nid.
        $result = reset($migration->getIdMap()->lookupDestinationIds([$source_id]));
        if (!$result) {
            return [];
        }
        return $result;
    }
}