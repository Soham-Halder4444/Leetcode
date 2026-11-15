# Write your MySQL query statement below
SELECT t.activity_date AS 'day',COUNT(DISTINCT(user_id)) AS 'active_users' FROM(SELECT *
FROM Activity
WHERE activity_date <= '2019-07-27'
AND DATEDIFF('2019-07-27', activity_date) < 30)t
GROUP BY t.activity_date