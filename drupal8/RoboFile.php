<?php

use ForumOne\Cbcny\Dev\Robo\CopyFilesTaskLoader;
use Psr\Log\LoggerAwareInterface;
use Psr\Log\LoggerAwareTrait;
use Robo\Collection\CollectionBuilder;
use Robo\Common\ConfigAwareTrait;
use Robo\Contract\ConfigAwareInterface;
use Robo\Contract\TaskInterface;
use Robo\State\Data as RoboStateData;
use Robo\Task\Filesystem\loadTasks as FilesystemTaskLoader;
use Sweetchuck\Robo\Git\GitComboTaskLoader;
use Symfony\Component\Filesystem\Filesystem;
use Symfony\Component\Finder\Finder;

class RoboFile extends Robo\Tasks implements LoggerAwareInterface, ConfigAwareInterface {

  use LoggerAwareTrait;
  use ConfigAwareTrait;
  use FilesystemTaskLoader;
  use CopyFilesTaskLoader;
  use GitComboTaskLoader;

  /**
   * @var string
   */
  protected $releaseDir = '../drupal8-release';

  /**
   * @var string
   */
  protected $docroot = 'web';

  /**
   * @command cbcny:release:pantheon
   */
  public function releasePantheon(): CollectionBuilder {
    $themeDir = "{$this->docroot}/themes/cbcny_theme";

    return $this
      ->collectionBuilder()
      ->addTask($this->getTaskNpmInstall($themeDir))
      ->addTask($this->getTaskNpmBuild($themeDir))
      ->addCode($this->getTaskPrepareDir($this->releaseDir))
      ->addTask($this->getTaskGitCloneAndClean())
      ->addCode($this->getTaskCollectFilesToCopy())
      ->addTask($this->getTaskCopyFiles())
      ->addCode($this->getTaskRenameFiles())
      ->addTask($this->getTaskComposerUpdate())
      ->addTask($this->getTaskCreateGitignore())
      ->addCode($this->getTaskCleanup())
      ->addTask($this->getTaskCheckIgnoredFiles())
      ->addTask($this->getTaskGitCommit())
      ;
  }

  protected function getTaskNpmInstall(string $dir): TaskInterface {
    return $this
      ->taskNpmInstall()
      ->dir($dir);
  }

  protected function getTaskNpmBuild(string $dir):TaskInterface {
    return $this
      ->taskExec(sprintf('grunt build'))
      ->dir($dir);
  }

  protected function getTaskPrepareDir(string $dir): Closure {
    return function () use ($dir): int {
      try {
        $fs = new Symfony\Component\Filesystem\Filesystem();
        $fs->mkdir($dir);

        $files = (new Symfony\Component\Finder\Finder())
          ->in($dir)
          ->ignoreDotFiles(FALSE)
          ->ignoreVCS(FALSE)
          ->depth('== 0');
        /** @var \Symfony\Component\Finder\SplFileInfo $file */
        foreach ($files as $file) {
          $fs->remove($file->getPathname());
        }
      }
      catch (Exception $e) {
        return 1;
      }

      return 0;
    };
  }

  protected function getTaskGitCloneAndClean(): TaskInterface {
    $config = $this->getConfig();
    $remoteUrl = (string) $config->get('release.pantheon.remoteUrl');
    if (!$remoteUrl) {
      return $this
        ->collectionBuilder()
        ->addCode(
          function (): int {
            $this->logger->notice(
              '{taskName} - skipped because of the lack of release.pantheon.remoteUrl',
              [
                'taskName' => 'Git clone and clean',
              ]
            );

            return 0;
          }
        );
    }

    $remoteName = (string) $config->get('release.pantheon.remoteName');
    $remoteBranch = (string) $config->get('release.pantheon.remoteBranch');
    $localBranch = (string) $config->get('release.pantheon.localBranch');

    return $this
      ->taskGitCloneAndClean()
      ->setSrcDir('..')
      ->setWorkingDirectory($this->releaseDir)
      ->setRemoteName($remoteName)
      ->setRemoteUrl($remoteUrl)
      ->setRemoteBranch($remoteBranch)
      ->setLocalBranch($localBranch);
  }

  protected function getTaskCopyDir(string $folder): TaskInterface {
    return $this->taskCopyDir([
      $folder => "{$this->releaseDir}/{$folder}",
    ]);
  }

  protected function getTaskCollectFilesToCopy(): Closure {
    return function (RoboStateData $data): int {
      $data['filesToCopy'] = $this->collectFilesToCopy();

      return 0;
    };
  }

  protected function getTaskCopyFiles(): TaskInterface {
    return $this
      ->taskCbcnyCopyFiles()
      ->setSrcDir('.')
      ->setDstDir($this->releaseDir)
      ->deferTaskConfiguration('setFiles', 'filesToCopy');
  }

  protected function getTaskRenameFiles(): Closure {
    return function (): int {
      $fs = new Filesystem();
      $sitesDefault = "{$this->releaseDir}/{$this->docroot}/sites/default";
      $pairs = [
        "$sitesDefault/settings.pantheon.php" => "$sitesDefault/settings.local.php",
      ];

      try {
        foreach ($pairs as $src => $dst) {
          $this->logger->debug(
            'Rename <info>{src}</info> to <info>{dst}</info>',
            [
              'src' => $src,
              'dst' => $dst,
            ]
          );
          $fs->rename($src, $dst, TRUE);
        }
      }
      catch (Exception $e) {
        $this->logger->error($e->getMessage());

        return 1;
      }

      return 0;
    };
  }

  protected function getTaskComposerUpdate(): TaskInterface {
    return $this
      ->taskComposerUpdate()
      ->dir($this->releaseDir)
      ->noDev()
      ->option('lock');
  }

  protected function getTaskCreateGitignore(): TaskInterface {
    $content = implode("\n", [
      "/{$this->docroot}/sites/*/private/",
      "/{$this->docroot}/sites/*/files/",
    ]);

    return $this
      ->taskWriteToFile("{$this->releaseDir}/.gitignore")
      ->text($content);
  }

  protected function getTaskCleanup(): Closure {
    return function (): int {
      $fs = new Filesystem();

      try {
        $fs->remove([
          "{$this->releaseDir}/config/sync/.gitkeep",
          "{$this->releaseDir}/patches/",
          "{$this->releaseDir}/{$this->docroot}/themes/cbcny_theme/bower_components/breakpoint-sass",
          "{$this->releaseDir}/{$this->docroot}/themes/cbcny_theme/bower_components/sassy-maps",
          "{$this->releaseDir}/{$this->docroot}/themes/cbcny_theme/tasks",
        ]);
      } catch (Exception $e) {
        $this->logger->error($e->getMessage());

        return 1;
      }

      $command = sprintf(
        'find %s -mindepth %s -name %s -exec rm -rf {} +',
        escapeshellarg("./{$this->releaseDir}"),
        escapeshellarg(2),
        escapeshellarg('.git')
      );

      try {
        $result = $this
          ->taskExec($command)
          ->run();

        return $result->wasSuccessful() ? 0 : 1;
      }
      catch (Exception $e) {
        return 1;
      }
    };
  }

  protected function getTaskCheckIgnoredFiles(): TaskInterface {
    $command = sprintf(
      'git status --ignored --porcelain | grep --color=%s --invert-match %s',
      'never',
      '^!! '
    );

    return $this
      ->taskExec($command)
      ->dir($this->releaseDir)
      ->printOutput(FALSE);
  }

  protected function getTaskGitCommit(): TaskInterface {
    return $this
      ->taskGitStack()
      ->dir($this->releaseDir)
      ->add('.');
  }

  protected function collectFilesToCopy(): array {
    $return = [];
    $packagePath = '.';

    $releaseDir = $this->releaseDir;
    $releaseDirSafe = preg_quote($releaseDir, '@');

    $docroot = $this->docroot;
    $docrootSafe = preg_quote($docroot, '@');

    $outerSitesDir = 'sites';
    $outerSitesDirSafe = preg_quote($outerSitesDir, '@');

    $files = (new Finder())
      ->in($packagePath)
      ->notPath("@^{$releaseDirSafe}@")
      ->notPath("@^{$docrootSafe}/sites/simpletest/@")
      ->name('*.yml')
      ->name('*.twig')
      ->files();

    $dirs = [
      "$docrootSafe/modules",
      "$docrootSafe/themes",
      "$docrootSafe/profiles",
      "$docrootSafe/sites/[^/]+/modules",
      "$docrootSafe/sites/[^/]+/themes",
      "$docrootSafe/sites/[^/]+/profiles",
      "$docrootSafe/sites/[^/]+/libraries",
      'drush/Commands',
      "$docrootSafe/sites/[^/]+/drush/Commands",
    ];
    foreach ($dirs as $dir) {
      $files
        ->path("@^$dir/custom/@")
        ->notPath("@$dir/custom/[^/]+/node_modules/@");
    }

    $files
      ->path("@^$docrootSafe/themes/cbcny_theme/@")
      ->notPath("@^$docrootSafe/themes/cbcny_theme/node_modules/@");

    $this
      ->configFinderGit($files)
      ->configFinderPhp($files)
      ->configFinderCss($files, FALSE)
      ->configFinderJavaScript($files)
      ->configFinderImages($files)
      ->configFinderFont($files)
      ->configFinderOs($files)
      ->configFinderTypeScript($files)
      ->configFinderCi($files)
      ->configFinderRuby($files)
      ->configFinderDocker($files)
      ->configFinderIde($files);

    $return[] = $files;

    $return[] = (new Finder())
      ->in($packagePath)
      ->notPath("@^{$releaseDirSafe}@")
      ->notPath("@^{$docrootSafe}/sites/simpletest/@")
      ->path("@$docrootSafe/sites/[^/]+/@")
      ->name('settings.php')
      ->name('settings.pantheon.php')
      ->name('services.yml')
      ->files();

    $files = (new Finder())
      ->in($packagePath)
      ->notPath("@^{$releaseDirSafe}@")
      ->notPath("@^{$docrootSafe}/sites/simpletest/@")
      ->path("@^{$outerSitesDirSafe}/[^/]+/translations/@")
      ->path("@^{$outerSitesDirSafe}/[^/]+/config/@")
      ->ignoreDotFiles(FALSE)
      ->files();

    $return[] = $files;

    $return[] = (new Finder)
      ->in($packagePath)
      ->notPath("@^{$releaseDirSafe}@")
      ->notPath("@^{$docrootSafe}/sites/simpletest/@")
      ->path("@^$docrootSafe/libraries/@")
      ->path('@^config/@')
      ->path('@^drush/@')
      ->path('@^patches/@')
      ->ignoreDotFiles(FALSE)
      ->files();

    $return[] = (new Finder())
      ->in($packagePath)
      ->path($docroot)
      ->depth('== 1')
      ->name('*.png')
      ->name('*.ico')
      ->name('*.svg')
      ->name('robots.txt');

    $return[] = "$docroot/autoload.php";
    $return[] = "$docroot/index.php";
    $return[] = "$docroot/.htaccess";
    $return[] = "$docroot/favicon.ico";
    $return[] = "$docroot/robots.txt";
    $return[] = 'scripts/composer/ScriptHandler.php';
    $return[] = 'composer.json';
    $return[] = 'composer.lock';
    $return[] = 'pantheon.yml';

    return $return;
  }

  /**
   * @return $this
   */
  protected function configFinderGit(Finder $finder) {
    $finder
      ->notPath('.git')
      ->notPath('.gtm')
      ->notName('.gitignore');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderPhp(Finder $finder) {
    $finder
      ->name('*.php')
      ->name('*.inc')
      ->name('*.install')
      ->name('*.module')
      ->name('*.theme')
      ->name('*.profile')
      ->name('*.engine')
      ->notPath('vendor')
      ->notName('.phpbrewrc')
      ->notName('composer.lock')
      ->notName('phpcs.xml.dist')
      ->notName('phpcs.xml')
      ->notName('phpunit.xml.dist')
      ->notName('phpunit.xml');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderCss(Finder $finder, bool $withImportable) {
    $finder
      ->name('*.css')
      ->notPath('.sass-cache')
      ->notName('config.rb')
      ->notName('.sass-lint.yml')
      ->notName('sass-lint.yml')
      ->notName('.scss-lint.yml')
      ->notName('scss-lint.yml')
      ->notName('*.css.map');

    if ($withImportable) {
      $finder
        ->name('/^_.+\.scss$/')
        ->name('/^_.+\.sass$/');
    }

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderJavaScript(Finder $finder) {
    $finder
      ->name('*.js')
      ->notPath('node_modules')
      ->notName('.npmignore')
      ->notName('*.js.map')
      ->notName('npm-debug.log')
      ->notName('npm-shrinkwrap.json')
      ->notName('package.json')
      ->notName('yarn.lock')
      ->notName('yarn-error.log')
      ->notName('.nvmrc')
      ->notName('.eslintignore')
      ->notName('.eslintrc.json')
      ->notName('bower.json')
      ->notName('.bowerrc')
      ->notName('Gruntfile.js')
      ->notName('gulpfile.js')
      ->notName('.istanbul.yml');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderTypeScript(Finder $finder) {
    $finder
      ->name('*.td.ts')
      ->notPath('typings')
      ->notName('typings.json')
      ->notName('tsconfig.json')
      ->notName('tsd.json')
      ->notName('tslint.json');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderImages(Finder $finder) {
    $finder
      ->name('*.png')
      ->name('*.jpeg')
      ->name('*.jpg')
      ->name('*.gif')
      ->name('*.svg')
      ->name('*.ttf')
      ->name('*.ico');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderFont(Finder $finder) {
    $finder
      ->name('*.otf')
      ->name('*.woff')
      ->name('*.woff2')
      ->name('*.eot');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderRuby(Finder $finder) {
    $finder
      ->notPath('.bundle')
      ->notName('.ruby-version')
      ->notName('.ruby-gemset')
      ->notName('.rvmrc')
      ->notName('Gemfile')
      ->notName('Gemfile.lock');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderDocker(Finder $finder) {
    $finder
      ->notName('Dockerfile')
      ->notName('docker-compose.yml')
      ->notName('.dockerignore');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderCi(Finder $finder) {
    $finder
      ->notName('Jenkinsfile')
      ->notPath('.gitlab')
      ->notName('.gitlab-ci.yml')
      ->notPath('.github')
      ->notName('.travis.yml')
      ->notPath('.circle')
      ->notName('circle.yml');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderOs(Finder $finder) {
    $finder
      ->notName('.directory')
      ->notName('.directory.lock.*.test')
      ->notName('.DS_Store')
      ->notName('._*');

    return $this;
  }

  /**
   * @return $this
   */
  protected function configFinderIde(Finder $finder) {
    $finder
      ->notPath('.idea')
      ->notPath('.phpstorm.meta.php')
      ->notName('.phpstorm.meta.php')
      ->notName('*___jb_old___')
      ->notPath('.kdev4')
      ->notName('*.kdev4')
      ->notName('.kdev*')
      ->notName('cifs*')
      ->notName('*~')
      ->notName('.*.kate-swp')
      ->notName('.kateconfig')
      ->notName('.kateproject')
      ->notPath('.kateproject.d')
      ->notName('*.loalize')
      ->notPath('nbproject')
      ->notPath('.settings')
      ->notName('.buildpath')
      ->notName('.project')
      ->notName('.*.swp')
      ->notName('.phing_targets')
      ->notName('nohup.out')
      ->notName('.~lock.*');

    return $this;
  }

}
