@api
Feature: Blogs and posts display together
  In order to view research content
  As a visitor
  Blog posts should not be differentiated from Reports

  Scenario: Viewing blogs and reports on the research page
    Given I am an anonymous user
    When I am on "/research"
    Then I should not see the heading "Latest Blog Posts"
    And I should not see the heading "Latest Reports"
    And I should not see the link "See More Reports"
    And I should not see the link "See More Blog Posts"
    And I should see the link "See More Research"

  Scenario: Clicking through to the research page
    Given I am an anonymous user
    And I am on "/research"
    When I click "See More Research"
    Then I should not get a 404 HTTP response
    And I should see the heading "More Research"
    And I should see the heading "Search Within Research"