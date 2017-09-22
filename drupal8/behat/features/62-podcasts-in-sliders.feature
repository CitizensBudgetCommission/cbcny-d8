@api
Feature: Podcasts inclusion in sliders
  In order to highlight podcast episodes
  As a site administrator
  I must be allowed to feature podcast episodes in sliders.

  Scenario: Add a podcast episode to the frontpage slider
    Given I am viewing a "podcast_episode" content:
      | title | Testing podcast episode |
      | field_published_date | date: 2017-09-22 - time: 07:23:18 |
      | field_term_topic     | City Budget                       |
      | field_teaser_plain   | Plain text teaser content.        |
      | field_soundcloud     | https://soundcloud.com/ggcbcpodcast/whats-the-data-point-ep-2-44 |
      | status               | 1                                                                |
    And I am logged in as a user with the "administrator" role
    When I am on "/block/13"
    And for "Featured items" I enter "Testing podcast episode"
    When I press the "Save" button
    Then I should not see the error message containing "There are no entities matching"
    When I am an anonymous user
    And I am on the homepage
    Then I should see the heading "Testing podcast episode"
    And I should not see the text "Post Type"


  Scenario: Add a podcast episode to a topics slider
    Given I am viewing a "podcast_episode" content:
      | title | Testing podcast episode |
      | field_published_date | date: 2017-09-22 - time: 07:23:18 |
      | field_term_topic     | City Budget                       |
      | field_teaser_plain   | Plain text teaser content.        |
      | field_soundcloud     | https://soundcloud.com/ggcbcpodcast/whats-the-data-point-ep-2-44 |
      | status               | 1                                                                |
    And I am logged in as a user with the "administrator" role
    And I am on "/node/add/section"
    When I fill in the following:
      | Title | My testing section |
      | Featured Content | Testing podcast episode |
    And I press the "Save and publish" button
    Then I should not see the error message containing "There are no entities matching"
    When I am an anonymous user
    And I visit the "section" content "My testing section"
    Then I should not see the text "Post Type"
    And I should see the heading "Testing podcast episode"