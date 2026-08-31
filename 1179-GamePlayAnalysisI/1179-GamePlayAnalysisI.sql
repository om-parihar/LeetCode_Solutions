-- Last updated: 8/31/2026, 4:28:02 PM
# Write your MySQL query statement below
 SELECT player_id,
 MIN(event_date) as first_login
 FROM Activity
 GROUP BY player_id;