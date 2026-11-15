# Write your MySQL query statement below
SELECT DISTINCT(t1.num) AS 'ConsecutiveNums' FROM (SELECT *,LAG(t.one) OVER() AS 'two'FROM (SELECT*,LAG(num) OVER() AS 'one' FROM Logs)t)t1
WHERE t1.num=t1.one AND t1.num=t1.two