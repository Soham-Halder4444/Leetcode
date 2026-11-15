# Write your MySQL query statement below
SELECT c.category,
       COUNT(t.income) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
) c
LEFT JOIN (
    SELECT income,
           CASE 
             WHEN income < 20000 THEN 'Low Salary'
             WHEN income > 50000 THEN 'High Salary'
             ELSE 'Average Salary'
           END AS category
    FROM Accounts
) t
ON c.category = t.category
GROUP BY c.category;
