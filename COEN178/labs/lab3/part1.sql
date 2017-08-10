SELECT deptid, COUNT(empno)
FROM L_EMP
GROUP BY deptid;

SELECT deptid AS deptno, COUNT(empno) AS empcount
FROM L_EMP
GROUP BY deptid; 
