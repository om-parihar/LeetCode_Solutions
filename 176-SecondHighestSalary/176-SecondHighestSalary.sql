-- Last updated: 7/25/2026, 11:01:06 PM
# Write your MySQL query statement below
SELECT IFNULL(
    (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary desc
    LIMIT 1 OFFSET 1        
    ),
    NULL
) AS SecondHighestSalary