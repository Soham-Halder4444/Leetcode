# Write your MySQL query statement below
SELECT t1.visited_on,t1.cumsum AS 'amount',ROUND(t1.cumsum/7,2) AS 'average_amount' FROM (SELECT *,SUM(t.sum) OVER(ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) AS 'cumsum' FROM (SELECT visited_on,SUM(amount) AS 'sum' FROM Customer
GROUP BY visited_on
ORDER BY visited_on)t
LIMIT 6,10000)t1