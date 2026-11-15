# Write your MySQL query statement below
SELECT t.employee_id,t.department_id FROM (SELECT *,COUNT(*) OVER(PARTITION BY employee_id) AS 'count' FROM Employee)t
WHERE (t.primary_flag='N' AND t.count=1) OR (t.primary_flag='Y')