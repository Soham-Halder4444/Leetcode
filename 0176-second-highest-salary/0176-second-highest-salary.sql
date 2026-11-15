# Write your MySQL query statement below
SELECT CASE WHEN COUNT(*)=0 THEN NULL ELSE t.salary END AS 'SecondHighestSalary' FROM(SELECT * FROM Employee GROUP BY salary ORDER BY salary DESC LIMIT 1,1)t