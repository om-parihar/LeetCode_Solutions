-- Last updated: 8/31/2026, 4:27:02 PM
# Write your MySQL query statement below
SELECT user_id,
CONCAT(upper(left(name,1)),lower(substr(name,2))) AS name FROM Users
ORDER BY user_id;