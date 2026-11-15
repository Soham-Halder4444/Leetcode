# Write your MySQL query statement below
SELECT DISTINCT(t.class) AS 'class' FROM(SELECT *,count(*) OVER(PARTITION BY class)AS 'count' FROM Courses)t
WHERE t.count>=5