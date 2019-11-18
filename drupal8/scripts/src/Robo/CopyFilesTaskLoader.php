<?php

declare(strict_types = 1);

namespace ForumOne\Cbcny\Dev\Robo;

use ForumOne\Cbcny\Dev\Robo\Task\CopyFilesTask;

trait CopyFilesTaskLoader {

  /**
   * @return \Robo\Collection\CollectionBuilder|\ForumOne\Cbcny\Dev\Robo\Task\CopyFilesTask
   */
  protected function taskCbcnyCopyFiles(array $options = []) {
    /** @var \ForumOne\Cbcny\Dev\Robo\Task\CopyFilesTask $task */
    $task = $this->task(CopyFilesTask::class);
    $task->setOptions($options);

    return $task;
  }

}
