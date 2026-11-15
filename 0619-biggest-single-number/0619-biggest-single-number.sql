# Write your MySQL query statement below
SELECT MAX(t.num) AS 'num' FROM (SELECT *,COUNT(*) AS 'count' FROM MyNumbers GROUP BY num)t WHERE t.count=1