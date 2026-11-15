# Write your MySQL query statement below
SELECT t1.person_name FROM (SELECT *,SUM(T.weight) OVER(ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) AS 'cumsum' FROM (SELECT * FROM Queue ORDER BY Turn)t)t1
WHERE t1.cumsum<=1000
ORDER BY t1.cumsum DESC LIMIT 1