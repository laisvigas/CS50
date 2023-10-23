-- write a SQL query to list the titles of all episodes in Cyberchase’s original season, Season 1.

SELECT
  title
FROM
  episodes
WHERE
  season = 1;