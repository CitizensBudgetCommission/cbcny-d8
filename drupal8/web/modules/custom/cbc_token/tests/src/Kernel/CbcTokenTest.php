<?php

namespace Drupal\Tests\cbc_token\Kernel;

use Drupal\field\Entity\FieldConfig;
use Drupal\field\Entity\FieldStorageConfig;
use Drupal\file\Entity\File;
use Drupal\node\Entity\Node;
use Drupal\node\Entity\NodeType;
use Drupal\paragraphs\Entity\Paragraph;
use Drupal\paragraphs\Entity\ParagraphsType;
use Drupal\Tests\token\Functional\TokenTestTrait;
use Drupal\Tests\token\Kernel\KernelTestBase as TokenKernelTestBase;

/**
 * Tests CBC custom tokens.
 *
 * @group cbc_custom
 */
class CbcTokenTest extends TokenKernelTestBase {

  use TokenTestTrait;

  /**
   * Modules to enable.
   *
   * @var array
   */
  public static $modules = [
    'cbc_token',
    'entity_reference_revisions',
    'field',
    'file',
    'image',
    'image_test',
    'node',
    'paragraphs',
    'user',
    'pathauto',
  ];

  /**
   * {@inheritdoc}
   */
  public function setUp() {
    parent::setUp();

    $this->installEntitySchema('node');
    $this->installEntitySchema('paragraph');
    $this->installEntitySchema('file');
    $this->installEntitySchema('user');

    $this->installSchema('file', ['file_usage']);
    $this->installSchema('node', ['node_access']);

    \Drupal::moduleHandler()->loadInclude('paragraphs', 'install');

    // Create the article content type.
    $node_type = NodeType::create([
      'type' => 'article',
    ])->save();
    // Create the Hero paragraph type.
    $paragraph_type = ParagraphsType::create([
      'id' => 'hero',
    ]);
    $paragraph_type->save();
    // Create the image field on the Hero paragraph.
    FieldStorageConfig::create([
      'field_name' => 'field_image',
      'entity_type' => 'paragraph',
      'type' => 'image',
      'cardinality' => 1,
    ])->save();
    FieldConfig::create([
      'field_name' => 'field_image',
      'entity_type' => 'paragraph',
      'bundle' => 'hero',
      'settings' => [
        'file_extensions' => 'png',
      ],
    ])->save();
    // Create the hero field on the article content type.
    FieldStorageConfig::create([
      'field_name' => 'field_hero',
      'entity_type' => 'node',
      'target_type' => 'paragraph',
      'type' => 'entity_reference_revisions',
      'cardinality' => 1,
      'settings' => [
        'target_type' => 'paragraph',
      ],
    ])->save();
    FieldConfig::create([
      'field_name' => 'field_hero',
      'entity_type' => 'node',
      'bundle' => 'article',
    ])->save();

    // Create another content type that will not receive field_hero.
    $node_type = NodeType::create([
      'type' => 'page',
    ])->save();
  }

  /**
   * Tests hero image tokens.
   */
  public function testHeroImageToken() {
    // Create an image.
    $image = File::create([
      'fid' => 1,
      'filename' => 'test.png',
      'filesize' => 100,
      'uri' => 'public://images/test.jpg',
      'filemime' => 'image/jpeg',
    ]);
    $image->save();

    // Create a hero paragraph with the hero_image value set.
    $paragraph = Paragraph::create([
      'type' => 'hero',
    ]);
    $paragraph->field_image = $image->id();
    $paragraph->save();

    // Create a node with nothing in the hero field.
    $node = Node::create([
      'type' => 'article',
      'title' => 'test node title',
    ]);
    $node->save();
    // The token for that node should return our fallback image.
    $fallback_image = 'http://localhost/themes/cbcny_theme/images/bg/hero--post.jpg';
    $this->assertToken('current-page', array('node' => $node), 'hero-image', $fallback_image);

    // Add our hero paragraph.
    $node->field_hero = $paragraph;
    $node->save();
    // The token for that node should return our image URI.
    $this->assertToken('current-page', array('node' => $node), 'hero-image', $image->createFileUrl(FALSE));

    // Create a node without a hero field.
    $node = Node::create([
      'type' => 'page',
      'title' => 'test page node',
    ]);
    $node->save();
    // The token for that node should return our fallback image.
    $this->assertToken('current-page', array('node' => $node), 'hero-image', $fallback_image);
  }

}
