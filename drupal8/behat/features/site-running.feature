Feature: Test Basic site availability
  In order to access the site
  As a visitor
  The site must be responding.

  Scenario: Test the ability to load the front page.
    Given I am on the homepage
    Then I should see the heading "Browse Topics"