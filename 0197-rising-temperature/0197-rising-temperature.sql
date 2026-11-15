# Write your MySQL query statement below
SELECT id FROM (SELECT *,LAG(temperature) OVER() AS 'Lower', LAG(recordDate) OVER() AS 'Lower_date' FROM(SELECT * FROM Weather ORDER BY recordDate ASC)t1)t2
WHERE t2.Lower IS NOT NULL AND t2.temperature>t2.Lower AND Lower_date IS NOT NULL
AND DATEDIFF(recordDate,Lower_date)=1;