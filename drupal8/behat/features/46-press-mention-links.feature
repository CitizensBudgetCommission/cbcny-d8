@api
Feature: Press mention link behavior
  In order to learn about CBC mentions in the press
  As a visitor
  Press mention content must display appropriately.

  Scenario: View a link with a title
    Given I am viewing a "news" content:
    | title     | News test        |
    | status    | 1              |
    | field_source_url | Link to google - http://google.com/ |
    Then I should see the link "Link to google"

  Scenario: View a link without a title
    Given I am viewing a "news" content:
      | title     | News test        |
      | status    | 1              |
      | field_source_url | http://google.com/ |
    Then I should not see the link "Link to google"
    Then I should see the link "Read the original article"

  Scenario: View a news node with body content
    Given the following content:
      """
      title: News text
      type: news
      langcode: en
      field_teaser_plain: "Plain text content goes here."
      field_page_content:
        -
          type: full_text
          field_wysiwyg: <p>Some full text content here</p>
      """
    When I visit the "news" content "News text"
    Then I should see "Some full text content here"
    And I should not see "Plain text content goes here."

  Scenario: View a news node with no body content
    Given I am viewing a "news" content:
      | title     | News test        |
      | status    | 1              |
      | field_teaser_plain | Plain text content goes here. |
    Then I should not see "Some full text content here"
    And I should see "Plain text content goes here."
