# Write your MySQL query statement below
SELECT t2.name FROM (SELECT t1.name,COUNT(*) AS 'VAL' FROM Employee t1
LEFT JOIN Employee t2
ON t1.id=t2.managerId
GROUP BY t1.id)t2
WHERE t2.VAL>4;