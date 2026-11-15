# Write your MySQL query statement below
SELECT * FROM (SELECT t2.contest_id,ROUND(100*COUNT(DISTINCT(t2.user_id))/COUNT(DISTINCT(t1.user_id)),2) AS 'percentage' FROM Users t1
JOIN Register t2
GROUP BY t2.contest_id)t
ORDER BY t.percentage DESC,t.contest_id

