SELECT deptno, deptname, empcount
FROM L_DEPT,
(SELECT deptid AS deptno, COUNT(empno) AS empcount
FROM L_EMP
GROUP BY deptid) sq
WHERE sq.deptno = L_DEPT.deptid
ORDER BY deptid ASC;
