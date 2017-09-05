<?php

use Behat\Behat\Hook\Scope\AfterStepScope;
use Behat\MinkExtension\Context\RawMinkContext;
use Behat\Mink\Driver\Selenium2Driver;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawMinkContext {

  /**
   * @AfterStep
   */
  public function printLastResponseOnError(AfterStepScope $event) {
    if (!$event->getTestResult()->isPassed()) {
      $this->saveDebugScreenshot();
    }
  }

  /**
   * @Then /^save screenshot$/
   */
  public function saveDebugScreenshot() {
    $driver = $this->getSession()->getDriver();

    if (!$driver instanceof Selenium2Driver) {
      return;
    }

    $filename = microtime(TRUE) . '.png';
    $path = $this->getMinkParameter('kernel.root_dir') . '../screenshots';

    if (!file_exists($path)) {
      mkdir($path);
    }

    $this->saveScreenshot($filename, $path);
  }

}