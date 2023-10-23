/* 
write a query that counts the number of episodes released in the last 6 years, from 2018 to 2023, inclusive.
  -- You might find it helpful to know you can use BETWEEN with dates, such as BETWEEN '2000-01-01' AND '2000-12-31'. */

SELECT
  COUNT(title)
FROM
  episodes
WHERE
  air_date >= '2018-01-01'
  AND air_date <= '2023-12-31';