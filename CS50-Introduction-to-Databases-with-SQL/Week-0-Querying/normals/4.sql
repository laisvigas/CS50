-- write a SQL query to find the lowest normal ocean surface temperature.

SELECT
  "0m"
FROM
  normals
ORDER BY
  "0m"
LIMIT
  1;