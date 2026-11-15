# Write your MySQL query statement below
SELECT ROUND(SUM(sum),2) AS 'tiv_2016' FROM(SELECT *,ROUND(SUM(tiv_2016),2) AS 'sum' FROM (SELECT * FROM (SELECT *,COUNT(*) OVER(PARTITION BY lat,lon) AS 'count',COUNT(*) OVER(PARTITION BY tiv_2015) AS 'count1' FROM Insurance)t WHERE count=1 AND count1>1)t1
GROUP BY tiv_2015)t2


