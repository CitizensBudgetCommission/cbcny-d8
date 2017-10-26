@api
Feature: Search appearance
  In order to find information
  As a site visitor
  I must have working searches.

  Scenario: No broken handlers in search Views.
    Given I am logged in as a user with the "administrator" role
    When I am on "/admin/structure/views/view/advocacy_listing"
    Then I should not see the text "Broken/missing handler"
    When I am on "/admin/structure/views/view/reports_listing"
    Then I should not see the text "Broken/missing handler"
    When I am on "/admin/structure/views/view/blog_listing"
    Then I should not see the text "Broken/missing handler"
    When I am on "/admin/structure/views/view/news_listing"
    Then I should not see the text "Broken/missing handler"
    When I am on "/admin/structure/views/view/topics_listing"
    Then I should not see the text "Broken/missing handler"