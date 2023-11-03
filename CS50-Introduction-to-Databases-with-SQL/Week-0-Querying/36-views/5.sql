-- write a SQL query to find the highest contrast value of prints by Hokusai.
-- Name the column “Maximum Contrast”. Does Hokusai’s prints most contrasting print actually have much contrast?

SELECT
  contrast AS [Maximum Contrast]
FROM
  views
ORDER BY
  contrast
DESC LIMIT 1;