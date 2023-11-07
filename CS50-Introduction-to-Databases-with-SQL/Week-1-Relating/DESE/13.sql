-- Write a SQL query to answer a question you have about the data! The query should:
-- Involve at least one JOIN or subquery

-- This query finds the names of schools, public or charter, that reported more than 50% of dropped rate.

SELECT name
FROM schools
WHERE id IN
    (SELECT school_id
     FROM graduation_rates
     WHERE dropped > 50);
