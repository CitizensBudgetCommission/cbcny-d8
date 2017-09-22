@api
Feature: Podcast post type
  In order to view highlighted podcasts in the slideshow
  As a visitor
  The post type label should not be visible

  Scenario: Add a podcast episode to the front page
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
    And I press the "Save" button
    When I am an anonymous user
    And I am on the homepage
    Then I should see the heading "Testing podcast episode"
    And I should not see the text "Post Type"