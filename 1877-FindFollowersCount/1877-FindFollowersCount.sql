-- Last updated: 8/31/2026, 4:26:57 PM
# Write your MySQL query statement below
SELECT user_id,
count(*) as followers_count 
FROM Followers 
GROUP BY user_id
ORDER BY user_id;