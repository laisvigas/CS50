-- In 7.sql, write a SQL query to find the average ocean surface temperature,
-- rounded to two decimal places, along the equator.
-- Call the resulting column “Average Equator Ocean Surface Temperature”.
-- The equator’s ocean surface temperatures can be found at all longitudes between the latitudes -0.5° and 0.5°, inclusive.


SELECT
  ROUND(AVG("0m"), 2) AS [Average Equator Ocean Surface Temperature]
FROM
  normals
WHERE
  latitude >= -0.5
  AND latitude <= 0.5;