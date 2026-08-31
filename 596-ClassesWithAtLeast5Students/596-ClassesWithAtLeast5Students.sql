-- Last updated: 8/31/2026, 4:30:02 PM
-- # Write your MySQL query statement below
-- SELECT class
-- FROM (
--     SELECT class,
--     COUNT(*) as cnt
--     FROM Courses
--     GROUP BY class
-- ) t
-- WHERE cnt>=5;

SELECT class
FROM Courses
GROUP BY class
HAVING COUNT(*)>=5;