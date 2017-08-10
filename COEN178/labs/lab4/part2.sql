--
-- Exercise 3
--

--
-- Write a CREATE TABLE PROJECT_4 with the following properties:
--
-- projectid:  a string of char (you are free to choose the length), primary key
-- projectname: a string of char (you are free to choose the length)
-- resources: a number (10,2) cannot be null
-- dno: char length 5, foreign key into the table DEPT_4, matching primary key (deptno)
-- constraint: when a row in the DEPT_4 is deleted, any rows referencing the deleted row should be deleted as well
--


DROP TABLE WORKS_4;
DROP TABLE PROJECT_4;

CREATE TABLE PROJECT_4(
 projectid CHAR(10) PRIMARY KEY,
 projectname CHAR(20),
 resources NUMBER(10,2) NOT NULL,
 dno CHAR(5),
 CONSTRAINT dnocascade
 FOREIGN KEY(dno) REFERENCES DEPT_4(deptno) ON DELETE CASCADE
);

--
-- Insert 5 rows to PROJECT_4.
--

INSERT INTO PROJECT_4
	VALUES('A1', 'coffee', 34000.00, 'D1');
INSERT INTO PROJECT_4
	VALUES('A2', 'dream state', 20000.00, 'D1');
INSERT INTO PROJECT_4
	VALUES('B4', 'ice cream', 40000.00, 'D1');
INSERT INTO PROJECT_4
	VALUES('G6', 'hologram', 30000.00, 'D1');
INSERT INTO PROJECT_4
	VALUES('P1', 'teleporter', 70000.00, 'D1');

--
-- Write a CREATE TABLE Works_4 with the following properties:
--
-- empno: A string of char (same as that of EmpNo in the EMP_4 table)
-- projectno: A string of char (same as that of ProjectId in the Projects_4 table)
-- startdate: Date
-- empno and ProjectNo (together) form the primary key for this table.
-- empno is foreign key into EMP_4 table.
-- projectno is foreign key into PROJECT_4 table.
--



CREATE TABLE WORKS_4(
	empno INTEGER,
	projectno CHAR(10),
	startdate DATE,
	CONSTRAINT project_workers PRIMARY KEY(empno, projectno),
	FOREIGN KEY(empno) REFERENCES EMP_4(empno),
	FOREIGN KEY(projectno) REFERENCES PROJECT_4(projectid)
);

INSERT INTO DEPT_4
	VALUES('D13', 'research', 'SJ', 70000.00, 3000.00);

INSERT INTO EMP_4
	VALUES(1, 'Smith', 'D13', 60000.00, 'F');

INSERT INTO PROJECT_4
	VALUES('C8', 'quantum', 70000.00, 'D1');

INSERT INTO WORKS_4
	VALUES (1, 'P1', SYSDATE);
--
-- Insert 5 additional rows to WORKS_4.
--


INSERT INTO WORKS_4 VALUES(1, 'A1', '09-JAN-17');
INSERT INTO WORKS_4 VALUES(1, 'A2', '09-JAN-17');
INSERT INTO WORKS_4 VALUES(1, 'B4', '09-JAN-17');
INSERT INTO WORKS_4 VALUES(1, 'G6', '09-JAN-17');
INSERT INTO WORKS_4 VALUES(1, 'C8', '09-JAN-17');



--
-- Exercise 4
-- Write a query to show the employees (empno) working on a project.
-- Order by projectno.
--

SELECT projectno, empno
FROM WORKS_4
ORDER BY projectno;
