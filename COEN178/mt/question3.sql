-- Initialization

DROP TABLE Faculty CASCADE CONSTRAINTS;
DROP TABLE Student CASCADE CONSTRAINTS;
DROP TABLE University_Person CASCADE CONSTRAINTS;

CREATE TABLE University_Person(
  SSN char(10) PRIMARY KEY,
  name char(20),
  phone char(10)
);

CREATE TABLE Faculty(
  SSN char(10) NOT NULL,
  office char(20),
  FOREIGN KEY (SSN) REFERENCES University_Person(SSN)
);

CREATE TABLE Student(
  SSN char(10) NOT NULL,
  GPA number(2,1),
  FOREIGN KEY (SSN) REFERENCES University_Person(SSN)
);

INSERT INTO University_Person VALUES('1023043454', 'Josh', '4082343943');
INSERT INTO University_Person VALUES('1056563454', 'Jake', '4084526654');
INSERT INTO University_Person VALUES('1024512461', 'James', '4080134276');
INSERT INTO University_Person VALUES('7212465824', 'Jimmy', '4080791842');
INSERT INTO University_Person VALUES('0134276525', 'Johnson', '4089864273');

INSERT INTO Faculty VALUES('1023043454', 'Engineering');
INSERT INTO Faculty VALUES('1056563454', 'Admissions');

INSERT INTO Student VALUES('1024512461', 2.0);
INSERT INTO Student VALUES('7212465824', 3.1);
INSERT INTO Student VALUES('0134276525', 3.8);

-- Part A

CREATE OR REPLACE TRIGGER deletionFaculty
AFTER DELETE 
	ON Faculty
    FOR EACH ROW
BEGIN 
	DELETE FROM University_Person x
    WHERE x.SSN = :old.SSN;
END;
/
show errors;

CREATE OR REPLACE TRIGGER deletionStudent
AFTER DELETE 
	ON Student
    FOR EACH ROW
BEGIN 
	DELETE FROM University_Person x
    WHERE x.SSN = :old.SSN;
END;
/
show errors;

-- Part B

CREATE OR REPLACE PROCEDURE insertIntoFaculty(SSN IN University_Person.SSN%type, name IN University_Person.name%type, phone IN University_Person.phone%type, office IN Faculty.office%type)
AS
BEGIN
    INSERT INTO University_Person VALUES(SSN, name, phone);
    INSERT INTO Faculty VALUES(SSN, office);
END;
/
show errors;

-- Part C

CREATE OR REPLACE PROCEDURE insertIntoStudents(SSN IN University_Person.SSN%type, name IN University_Person.name%type, phone IN University_Person.phone%type, gpa IN Student.GPA%type)
AS
BEGIN
    INSERT INTO University_Person VALUES(SSN, name, phone);
    INSERT INTO Student VALUES(SSN, gpa);
END;
/
show errors;

-- Part D

CREATE OR REPLACE FUNCTION totalUnivPersons
RETURN CHAR IS 
	ret CHAR(5);
BEGIN 
	SELECT COUNT(*) INTO ret
	FROM University_Person;

	RETURN ret;
END;
/
show errors;

-- Part E

CREATE OR REPLACE FUNCTION totalStudents
RETURN CHAR IS 
	ret CHAR(5);
BEGIN 
	SELECT COUNT(*) INTO ret
	FROM Student;

	RETURN ret;
END;
/
show errors;