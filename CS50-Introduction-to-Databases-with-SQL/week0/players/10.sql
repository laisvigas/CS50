/*
write SQL query to answer a question of your choice. This query should:
Make use of AS to rename a column
Involve at least condition, using WHERE
Sort by at least one column using ORDER BY
*/

SELECT
  last_name AS [PLAYERS BORN IN NY],
  birth_year AS [BIRTH YEAR]
FROM
  players
WHERE
  birth_state = "NY"
AND
  birth_year
IS NOT NULL
ORDER BY
  birth_year
DESC
LIMIT 10;
