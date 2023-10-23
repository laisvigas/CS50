-- count the number of unique episode titles.

SELECT
  COUNT(DISTINCT title)
FROM
  episodes;