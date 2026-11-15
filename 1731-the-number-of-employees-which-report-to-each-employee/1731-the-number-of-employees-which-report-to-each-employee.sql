# Write your MySQL query statement below
SELECT t1.employee_id,t1.name,COUNT(*) AS 'reports_count',ROUND(AVG(t2.age)) AS 'average_age' FROM Employees t1
LEFT JOIN Employees t2
ON t1.employee_id=t2.reports_to
GROUP BY t1.employee_id
HAVING COUNT(t2.employee_id)>0
ORDER BY t1.employee_id