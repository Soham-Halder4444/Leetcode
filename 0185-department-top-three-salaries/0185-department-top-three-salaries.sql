# Write your MySQL query statement below
SELECT t.Department,t.name AS 'Employee',t.Salary FROM (SELECT *,DENSE_RANK() OVER(PARTITION BY t1.departmentId ORDER BY t1.salary DESC) AS 'rank' FROM Employee t1
LEFT JOIN (SELECT name AS 'Department',id AS 'did' FROM Department)t2
ON t1.departmentId=t2.did)t
WHERE t.rank<=3