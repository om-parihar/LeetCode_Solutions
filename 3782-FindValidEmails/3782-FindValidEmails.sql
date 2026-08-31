-- Last updated: 8/31/2026, 4:25:08 PM
# Write your MySQL query statement below
SELECT * FROM Users WHERE email REGEXP '^[A-Za-z0-9_]+@[A-Za-z]+\\.com$'
ORDER BY user_id;