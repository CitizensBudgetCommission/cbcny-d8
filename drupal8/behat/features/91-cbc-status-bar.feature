@api
Feature: CBC Status Bar
  In order to highlight key time-sensitive information
  As a site maintainer
  I should be able to set a status message on every page of the site.

  Scenario: Configuration forms share information to enable the bar.
    Given I am logged in as a user with the "administrator" role
    When I am on "/admin/config/system/cbc-status-bar"
    And I check the box "Enable the status bar"
    And for "Message" I enter "Here is a test message"
    And I press the "Save configuration" button
    Then I should not get a "500" HTTP response
    Then I am on "/admin/structure/block/manage/cbcstatusbar"
    And the "Message" field should contain "Here is a test message"
    And the "Enable the status bar" checkbox should be checked
    Given I am an anonymous user
    And I am on the homepage
    Then I should see text matching "Here is a test message"


  Scenario: Status bar does not displays when it should not.
    Given I am logged in as a user with the "administrator" role
    When I am on "/admin/config/system/cbc-status-bar"
    And I uncheck the box "Enable the status bar"
    And for "Message" I enter "Here is a test message"
    And I press the "Save configuration" button
    Then I am an anonymous user
    And I am on the homepage
    Then I should not see the text "Here is a test message"
