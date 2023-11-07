-- A parent wants to send their child to a district with many other students.
-- Write a SQL query to display the names of all school districts and the number of pupils enrolled in each.

-- name of all school districts
-- the number of pupils enrolled in each school district.

SELECT SUM(expenditures.pupils) AS total_pupils_enrolled,
       districts.name AS district_name
FROM districts
LEFT JOIN expenditures ON districts.id = expenditures.district_id
WHERE districts.name NOT LIKE '%non-op%'
GROUP BY districts.id,
         districts.name
HAVING total_pupils_enrolled IS NOT NULL;
