# Write your MySQL query statement below
SELECT t.product_name AS 'product_name',SUM(t.unit) AS 'unit' FROM (SELECT t1.product_id,t1.order_date,t1.unit,t2.product_name FROM Orders t1 
LEFT JOIN Products t2
ON t1.product_id=t2.product_id 
WHERE t1.order_date BETWEEN '2020-02-00' AND '2020-02-29')t
GROUP BY t.product_id HAVING SUM(t.unit)>=100