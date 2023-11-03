-- write a SQL query to find the highest normal ocean surface temperature.

SELECT
  "0m"
FROM
  normals
ORDER BY
  "0m" DESC
LIMIT
  1;