# Write your MySQL query statement below
SELECT t4.product_id,IFNULL(ROUND(SUM(t4.Total)/SUM(t4.units),2),0) AS 'average_price' FROM(SELECT t3.product_id,t3.units,IFNULL(t3.price*t3.units,0) AS 'Total' FROM(SELECT t1.product_id,t1.start_date,t1.end_date,t1.price,t2.purchase_date,t2.units FROM
Prices t1
LEFT JOIN UnitsSold t2
ON t1.product_id=t2.product_id
AND t2.purchase_date BETWEEN t1.start_date AND t1.end_date)t3)t4
GROUP BY t4.product_id
