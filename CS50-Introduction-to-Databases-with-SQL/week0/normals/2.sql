-- write a SQL query to find the normal temperature of the deepest sensor near the Gulf of Maine, at the same coordinate above
-- (42.5° of latitude and -69.5° of longitude)
-- The deepest sensor records temperatures at 225 meters of depth, so you can find this data in the 225m column.

SELECT
  "225m"
FROM
  normals
WHERE
  latitude = "42.5"
  AND longitude = "-69.5";