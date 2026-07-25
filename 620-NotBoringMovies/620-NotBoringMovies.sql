-- Last updated: 7/25/2026, 10:59:01 PM
# Write your MySQL query statement below
SELECT *
FROM Cinema
WHERE (id%2=1 AND(description is not null and description!='boring'))
    ORDER BY rating desc;