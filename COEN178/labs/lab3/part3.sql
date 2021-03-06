SELECT deptid, COUNT(*)
FROM L_EMP
GROUP BY deptid
HAVING COUNT(*) = (
SELECT MAX(COUNT(*))
FROM L_EMP
GROUP BY deptid); 

SELECT deptid, COUNT(*)
FROM L_EMP
GROUP BY deptid
HAVING COUNT(*) IN
(SELECT MAX(empcount)
FROM
(SELECT deptid, COUNT(*) AS empcount
FROM L_EMP
GROUP BY deptid));
