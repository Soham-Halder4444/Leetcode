# Write your MySQL query statement below
SELECT t1.customer_id FROM Customer t1
JOIN Product t2
GROUP BY t1.customer_id
HAVING COUNT(DISTINCT(t1.product_key))=COUNT(DISTINCT(t2.product_key))