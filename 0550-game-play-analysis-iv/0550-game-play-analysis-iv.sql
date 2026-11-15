# Write your MySQL query statement below
SELECT ROUND(SUM(CASE WHEN DATEDIFF(t.event_date, t.first) = 1 THEN 1 ELSE 0 END)/COUNT(DISTINCT(t.player_id)),2) AS 'fraction' FROM (SELECT *,MIN(event_date) OVER(PARTITION BY player_id) AS 'first' FROM Activity)t
