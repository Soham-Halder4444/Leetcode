# Write your MySQL query statement below
SELECT t.month,t.country,COUNT(*) AS 'trans_count',SUM(CASE WHEN t.state='approved'THEN 1 ELSE 0 END) AS 'approved_count',SUM(t.amount)AS 'trans_total_amount',SUM(CASE WHEN t.state='approved' THEN t.amount ELSE 0 END)AS 'approved_total_amount' FROM (SELECT *,DATE_FORMAT(trans_date, '%Y-%m') AS 'month' FROM Transactions)t
GROUP BY t.month,t.country