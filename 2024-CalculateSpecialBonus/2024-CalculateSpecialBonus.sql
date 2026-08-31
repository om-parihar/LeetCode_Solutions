-- Last updated: 8/31/2026, 4:26:36 PM
# Write your MySQL query statement below
SELECT employee_id,
    CASE
        when employee_id%2=0 OR name like 'M%' THEN 0
        ELSE salary
    END AS bonus
FROM Employees
ORDER BY employee_id;