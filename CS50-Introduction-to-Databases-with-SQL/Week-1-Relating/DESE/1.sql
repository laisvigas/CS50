-- Your colleague is preparing a map of all public schools in Massachusetts.
-- Write a SQL query to find the names and cities of all public schools in Massachusetts.
-- Keep in mind that not all schools in the schools table are considered traditional public schools.
-- Massachusetts also recognizes charter schools, which (according to DESE!) are considered distinct.

SELECT name,
       city
FROM schools
WHERE TYPE = "Public School";
