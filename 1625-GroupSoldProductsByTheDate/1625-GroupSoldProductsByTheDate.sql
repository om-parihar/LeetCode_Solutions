-- Last updated: 8/31/2026, 4:27:15 PM
# Write your MySQL query statement below
SELECT DISTINCT sell_date,
COUNT(DISTINCT product) as num_sold,
GROUP_CONCAT(DISTINCT product ORDER BY product) as products
FROM Activities
GROUP BY sell_date 
ORDER BY sell_date;