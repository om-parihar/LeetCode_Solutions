-- Last updated: 7/25/2026, 10:59:00 PM
# Write your MySQL query statement below
UPDATE Salary
SET sex=CASE
    WHEN sex='f'THEN 'm'
    WHEN sex='m'THEN 'f'
END;