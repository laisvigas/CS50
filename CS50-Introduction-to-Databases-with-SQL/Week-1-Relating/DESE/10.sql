-- In Massachusetts, school district expenditures are in part determined by local taxes on property (e.g., home) values.
-- Write a SQL query to find the 10 public school districts with the highest per-pupil expenditures.
-- Your query should return the names of the districts and the per-pupil expenditure for each.

-- Find the 10 public school districts with the highest per-pupil expenditures
-- Query must return NAMES OF THE DISTRICTS and PER-PUPIL EXPENDITURE

SELECT districts.name,
       expenditures.per_pupil_expenditure
FROM districts
LEFT JOIN expenditures ON districts.id = expenditures.district_id
WHERE districts.type = 'Public School District'
  AND expenditures.pupils IS NOT NULL
GROUP BY districts.id
ORDER BY per_pupil_expenditure DESC
LIMIT 10;
