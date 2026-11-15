# Write your MySQL query statement below
SELECT t1.customer_id,COUNT(DISTINCT(t1.visit_id)) AS 'count_no_trans' FROM Visits t1
LEFT JOIN Transactions t2
ON t1.visit_id=t2.visit_id
WHERE t1.visit_id NOT IN (SELECT visit_id FROM Transactions)
 GROUP BY t1.customer_id ;