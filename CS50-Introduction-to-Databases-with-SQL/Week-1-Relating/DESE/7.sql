-- DESE is preparing a report on schools in the Cambridge school district.
-- Write a SQL query to find the names of all schools in the Cambridge school district.

SELECT name
FROM schools
WHERE district_id IN
    (SELECT id
     FROM districts
     WHERE city = "Cambridge"
       AND TYPE = "Public School District" );
