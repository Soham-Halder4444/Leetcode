# Write your MySQL query statement below
SELECT t6.product_id,CASE WHEN t6.price IS NULL THEN 10 ELSE t6.price END AS 'price' FROM(SELECT t5.product_id,MAX(t5.new_price) AS 'price' FROM (SELECT t4.product_id,t3.new_price,t3.change_date FROM Products t4
LEFT JOIN (SELECT product_id,new_price,change_date FROM(SELECT *,MAX(t1.change_date) OVER(PARTITION BY t1.product_id) AS 'max' FROM (SELECT * FROM Products WHERE change_date<='2019-08-16')t1)t2
WHERE t2.change_date=t2.max)t3
ON t4.product_id=t3.product_id
AND t4.change_date=t3.change_date
ORDER BY t4.product_id,t3.change_date DESC)t5
GROUP BY t5.product_id)t6




