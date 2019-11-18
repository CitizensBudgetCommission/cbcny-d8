<?php

declare(strict_types = 1);

namespace ForumOne\Cbcny\Dev\Robo\Task;

use Robo\Result;
use Robo\Task\BaseTask;
use Symfony\Component\Filesystem\Filesystem;
use Webmozart\PathUtil\Path;

class CopyFilesTask extends BaseTask {

  /**
   * {@inheritdoc}
   */
  protected $taskName = 'CBCNY - Copy files';

  /**
   * @var \Symfony\Component\Filesystem\Filesystem
   */
  protected $fs;

  /**
   * @var string
   */
  protected $srcDir = '';

  public function getSrcDir(): string {
    return $this->srcDir;
  }

  /**
   * @return \ForumOne\Cbcny\Dev\Robo\Task\CopyFilesTask
   */
  public function setSrcDir(string $directory) {
    $this->srcDir = $directory;

    return $this;
  }

  /**
   * @var string
   */
  protected $dstDir = '';

  public function getDstDir(): string {
    return $this->dstDir;
  }

  /**
   * @return $this
   */
  public function setDstDir(string $directory) {
    $this->dstDir = $directory;

    return $this;
  }

  /**
   * @var string[]|\Symfony\Component\Finder\SplFileInfo[]|\Symfony\Component\Finder\Finder
   */
  protected $files = [];

  /**
   * @return string[]|\Symfony\Component\Finder\Finder|\Symfony\Component\Finder\SplFileInfo[]
   */
  public function getFiles() {
    return $this->files;
  }

  /**
   * @param string[]|\Symfony\Component\Finder\Finder|\Symfony\Component\Finder\SplFileInfo[] $files
   *
   * @return $this
   */
  public function setFiles($files) {
    $this->files = $files;

    return $this;
  }

  public function __construct(Filesystem $fs = NULL) {
    $this->fs = $fs ?: new Filesystem();
  }

  public function setOptions(array $options) {
    //parent::setOptions($options);

    if (array_key_exists('srcDir', $options)) {
      $this->setSrcDir($options['srcDir']);
    }

    if (array_key_exists('dstDir', $options)) {
      $this->setDstDir($options['dstDir']);
    }

    if (array_key_exists('files', $options)) {
      $this->setFiles($options['files']);
    }

    return $this;
  }

  /**
   * {@inheritdoc}
   */
  public function run() {
    foreach ($this->getFiles() as $file) {
      $this->runActionCopy($file);
    }

    return Result::success($this);
  }

  /**
   * @param string|string[]|\Symfony\Component\Finder\Finder|\Symfony\Component\Finder\Finder[]|\Symfony\Component\Finder\SplFileInfo|\Symfony\Component\Finder\SplFileInfo[] $file
   *
   * @return $this
   */
  protected function runActionCopy($file) {
    if (is_iterable($file)) {
      foreach ($file as $splFileInfo) {
        $this->runActionCopy($splFileInfo);
      }

      return $this;
    }

    $this->runActionCopySingle($file);

    return $this;
  }

  /**
   * @param string|\Symfony\Component\Finder\SplFileInfo $file
   *
   * @return $this
   */
  protected function runActionCopySingle($file) {
    $srcDir = $this->getSrcDir();
    $dstDir = $this->getDstDir();
    $isString = is_string($file);
    $relativeFileName = $isString ? $file : $file->getRelativePathname();
    $srcFileName = $isString ? Path::join($srcDir, $file) : $file->getPathname();
    $dstFileName = Path::join($dstDir, $relativeFileName);

    $this->printTaskDebug(
      'copy: {srcDir} {dstDir} {file}',
      [
        'srcDir' => $srcDir,
        'dstDir' => $dstDir,
        'file' => $relativeFileName,
      ]
    );
    $this->fs->copy($srcFileName, $dstFileName);

    return $this;
  }

}
