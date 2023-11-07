-- Another parent wants to send their child to a district with few other students.
-- Write a SQL query to find the name (or names) of the school district(s) with the single least number of pupils.
-- Report only the name(s).

SELECT districts.name
FROM districts
LEFT JOIN expenditures ON districts.id = expenditures.district_id
WHERE districts.name NOT LIKE '%non-op%'
  AND expenditures.pupils IS NOT NULL
  AND expenditures.pupils > 0
GROUP BY districts.id
ORDER BY SUM(expenditures.pupils) ASC
LIMIT 1;
