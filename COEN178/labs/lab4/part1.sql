--
-- Exercise 1
--
DROP TABLE EMP_4;
DROP TABLE DEPT_4;

CREATE TABLE DEPT_4 (
	deptno CHAR(5) PRIMARY KEY,
	deptname CHAR(10),
	location CHAR(20),
	budget NUMBER(10,2),
	extra_funds NUMBER(10,2),
	CONSTRAINT DEPT_4cons1 CHECK(budget >= 0),
	CONSTRAINT DEPT_4cons2 CHECK(extra_funds <= budget)
);

--
-- Success or Failure? If failure, why?
-- Comment out this query if it fails.
--

-- Failure because the second constraint is violated.
-- The budget is less than extra_funds.

/*
INSERT INTO DEPT_4
	VALUES('D2', 'testing', 'SFO', 20000.00, 50000.00);
*/

--
-- Success or Failure? If failure, why?
--

-- Success

INSERT INTO DEPT_4
	VALUES('D2', 'testing', 'SFO', 50000.00, 20000.00);

--
-- Success or Failure? If failure, why?
--

-- Success

INSERT INTO DEPT_4
	VALUES('D1', 'testing', 'SJ', NULL, NULL);

--
-- Success or Failure? If failure, why?
-- If failure, please resolve it before running this query (by modifying the query).
--

-- Failure because not every value can be modified to NOT NULL since null values exist.

UPDATE DEPT_4
SET budget = 55000.00;

ALTER TABLE DEPT_4
	MODIFY budget NUMBER(10,2) NOT NULL;

--
-- The following adds constraint limiting location to 'SJ', 'SFO', and 'LA'.
--
ALTER TABLE DEPT_4
	ADD CONSTRAINT DEPT_4cons3
	CHECK (location IN ('SJ', 'SFO', 'LA'));

--
-- Success or Failure? If failure, why?
--

-- Failure because the constraint is violated.
-- NY doesn't match any of the locations.

/*
INSERT INTO DEPT_4
	VALUES('D9', 'testing', 'NY', 10000, 1000);
*/

--
-- Use the following to check constraints.
--
SELECT status
FROM user_constraints
WHERE UPPER(constraint_name) = UPPER('Dept_4cons1');




--
-- Exercise 2
--
CREATE TABLE EMP_4 (
	empno INTEGER PRIMARY KEY,
	empname CHAR(20),
	deptid CHAR(5) NOT NULL,
	salary NUMBER(10,2),
	gender CHAR(2),
	CONSTRAINT dept_fkey
		FOREIGN KEY (deptid)
			REFERENCES DEPT_4(deptno)
		ON DELETE CASCADE
);


--
--  Use ALTER TABLE to add constraint limiting gender to 'M' or 'F'
--


ALTER TABLE EMP_4
	ADD CONSTRAINT EMP_4cons1
	CHECK (gender IN ('M', 'F'));


--
-- Success or Failure? If failure, why?
-- If failure, please resolve it before running this query (by writing another query above it).
--

-- Failure because D13 does not exist.

INSERT INTO DEPT_4
	VALUES('D13', 'research', 'SJ', 70000.00, 3000.00);

INSERT INTO EMP_4
	VALUES(1, 'Smith', 'D13', 60000.00, 'F');


--
-- Write query to delete row whose deptno is 'D13' in DEPT_4.
-- What happens to empno = 1 in EMP_4?
--

-- It gets deleted.

DELETE FROM DEPT_4
WHERE deptno='D13';


--
-- To confirm your script is correct, execute this script.
-- There should be no errors.
--
