# Write your MySQL query statement below
SELECT machine_id,ROUND(AVG(t2.time_taken),3) AS 'processing_time' FROM(SELECT *,(t.next_time-timestamp) AS 'time_taken' FROM (SELECT *,LEAD(t1.timestamp) OVER() AS'next_time' FROM(SELECT * FROM Activity ORDER BY machine_id,process_id,timestamp)t1)t
WHERE t.activity_type='start')t2 WHERE t2.activity_type='start' GROUP BY machine_id;
