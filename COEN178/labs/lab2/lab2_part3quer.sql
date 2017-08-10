SELECT empname 
FROM L_EMP, L_DEPT 
WHERE L_EMP.deptid = L_DEPT.deptid 
AND deptname = 'Testing';

SELECT empname 
FROM L_EMP 
WHERE deptid in 
(SELECT deptid 
FROM L_DEPT 
WHERE deptname = 'Testing');

SELECT empname 
FROM L_EMP 
WHERE exists 
(SELECT * 
FROM L_DEPT 
WHERE L_DEPT.deptid = L_EMP.deptid
AND deptname = 'Testing');

SELECT deptname 
FROM L_DEPT 
WHERE deptid not in
(SELECT deptid 
FROM L_EMP);

SELECT deptname
FROM L_DEPT
WHERE not exists
(SELECT *
FROM L_EMP
WHERE L_EMP.deptid = L_DEPT.deptid);