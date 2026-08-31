-- Last updated: 8/31/2026, 4:26:52 PM
# Write your MySQL query statement below
SELECT event_day as day,
emp_id,
SUM(out_time-in_time) as total_time
FROM Employees
GROUP BY emp_id,event_day;