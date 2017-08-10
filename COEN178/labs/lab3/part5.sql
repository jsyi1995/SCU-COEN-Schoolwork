SELECT empname, deptname
FROM L_DEPT NATURAL JOIN L_EMP;

SELECT empname, deptname
FROM L_DEPT LEFT JOIN L_EMP
ON L_DEPT.deptid = L_EMP.deptid; 
