-- There are 180 whole degrees of latitude.
-- In 10.sql, write a SQL query to determine how many points of latitude we have at least one data point for.
-- (Why might we not have data points for all latitudes?)

SELECT
  COUNT(DISTINCT latitude)
FROM
  normals;

-- I think there's no data points for all latitudes due to data collection limitations and several other reasons.