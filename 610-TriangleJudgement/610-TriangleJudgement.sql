-- Last updated: 7/25/2026, 10:59:03 PM
# Write your MySQL query statement below
select *
     , if(x+y>z and y+z>x and x+z>y, "Yes", "No") as triangle
from Triangle;