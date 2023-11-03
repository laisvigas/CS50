/*
write a SQL query to answer a question of your choice about the prints. The query should:
- Make use of AS to rename a column
- Involve at least one condition, using WHERE
- Sort by at least one column, using ORDER BY
*/

SELECT english_title AS [Title(s) With "SNOW" Word in it] FROM
  views
WHERE
  english_title
LIKE "%snow%" ORDER BY
  entropy
DESC;