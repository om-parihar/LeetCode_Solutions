-- Last updated: 7/25/2026, 10:59:04 PM
# Write your MySQL query statement below
select name
     , population
     , area
from world
where area>=3000000 or population>=25000000;