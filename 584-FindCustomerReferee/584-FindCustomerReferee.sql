-- Last updated: 7/25/2026, 10:59:06 PM
# Write your MySQL query statement below
SELECT name
FROM Customer
WHERE referee_id!=2 OR referee_id IS NULL;