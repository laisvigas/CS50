-- write a SQL query to find the English title and artist of the print with the highest brightness.
SELECT
  english_title,
  artist
FROM
  views
ORDER BY
  brightness DESC
LIMIT
  1;