DROP TABLE Branch CASCADE CONSTRAINTS;
DROP TABLE Employee CASCADE CONSTRAINTS;
DROP TABLE Owner CASCADE CONSTRAINTS;
DROP TABLE Property CASCADE CONSTRAINTS;
DROP TABLE Lease CASCADE CONSTRAINTS;

CREATE TABLE Branch(
  branchNo char(3) PRIMARY KEY,
  phone char(10),
  street char(20),
  city char(20),
  zip char(5)
);

CREATE TABLE Employee(
  empId char(10) PRIMARY KEY,
  branchNo char(3),
  name char(20),
  phone char(10),
  startDate date,
  jobType char(10),
  check (jobType in ('manager', 'supervisor')),
  FOREIGN KEY (branchNo) REFERENCES Branch(branchNo)
);

CREATE TABLE Owner(
  ownerId char(10) PRIMARY KEY,
  name char(20),
  phone char(10),
  street char(20),
  city char(20),
  zip char(5),
  fee integer
);

CREATE TABLE Property(
  propNum char(3) PRIMARY KEY,
  ownerId char(10),
  supId char(10),
  street char(20),
  city char(20),
  zip char(5),   
  roomNo char(2),
  monthlyRent number(10,2),
  propStatus char(10),
  AvailDate date,   
  check (propStatus in ('available', 'leased')),
  FOREIGN KEY (ownerId) REFERENCES Owner(ownerId),
  FOREIGN KEY (supId) REFERENCES Employee(empId)
);

CREATE TABLE Lease(
  propNum char(3),
  startDate date,
  endDate date,
  custName char(20),
  homePhone char(10),
  workPhone char(10),
  contactName char(20),
  contactPhone char(10),
  depositAmt number(10,2),
  rentAmt number(10,2),
  supervisorname char(20),
  FOREIGN KEY (propNum) REFERENCES Property(propNum) ON DELETE CASCADE,
  CONSTRAINT leasecon1 CHECK (depositAmt >= rentAmt),
  CONSTRAINT leasecon2 CHECK (endDate - startDate <= 366 AND endDate - startDate >= 182)
);

-- Constraint A

CREATE OR REPLACE TRIGGER manageLimit
FOR INSERT OR UPDATE
ON Employee
COMPOUND TRIGGER
v_MAX_PREREQS CONSTANT INTEGER := 1;
     v_CurNum INTEGER;	
	 v_cno INTEGER;

BEFORE EACH ROW IS
BEGIN
	v_cno := :new.branchNo;
END BEFORE EACH ROW;

AFTER STATEMENT IS
BEGIN
    SELECT COUNT(*) INTO v_CurNum FROM Employee 
		WHERE branchNo = v_cno AND jobType = 'manager' Group by branchNo;
		IF v_CurNum  > v_MAX_PREREQS THEN
			RAISE_APPLICATION_ERROR(-20001,'There is already a manager for this branch.');
		END IF;
END AFTER STATEMENT;
END;
/
show errors;

-- Constraint B

CREATE OR REPLACE TRIGGER tenpercentConstraint
BEFORE INSERT ON Lease
FOR EACH ROW
DECLARE
	amount number(10,2);
BEGIN
	BEGIN
		SELECT monthlyRent INTO amount FROM Property
		WHERE Property.propNum = :new.propNum;
	END;
	IF :new.endDate - :new.startDate = 182 THEN
		:new.rentAmt := Amount * 1.1;
	ELSE
		:new.rentAmt := Amount;
	END IF;		
END tenpercentConstraint;
/
Show Errors;

-- Constraint C

CREATE OR REPLACE TRIGGER changeStatus
BEFORE INSERT ON Lease
FOR EACH ROW
DECLARE
	Avail CHAR(10);
BEGIN
	BEGIN
		SELECT propStatus INTO Avail FROM Property
		WHERE propNum = :new.propNum;
		EXCEPTION
			WHEN no_data_found THEN
		DBMS_OUTPUT.put_line('Property not found');
	END;
	IF Avail IN ('leased') THEN
		RAISE_APPLICATION_ERROR(-20002,'Property not available');
	ELSE
		UPDATE Property
		SET propStatus = 'leased'
		where Property.propNum = :new.propNum;
		DBMS_OUTPUT.put_line('Property leased');
	END IF;
END;
/
show errors;

-- Constraint D

-- Tables enforce constraint.

-- Constraint E

CREATE OR REPLACE TRIGGER addtenpercentConstraint
AFTER DELETE
ON Lease
FOR EACH ROW
BEGIN
	UPDATE Property
	SET propStatus = 'available',
	monthlyRent=:OLD.RentAmt*1.1
	WHERE propNum=:OLD.propNum;
END;
/
show errors;

-- Additional Triggers

-- Initial Values

INSERT INTO BRANCH VALUES('23','4082343345','Saratoga Avenue','San Jose','95129');
INSERT INTO BRANCH VALUES('34','4082935345','1st Street','Los Angeles','92831');
INSERT INTO BRANCH VALUES('12','4082348394','El Camino Real','Santa Clara','95053');
INSERT INTO BRANCH VALUES('2','4082939434','Hollywood Blvd','Los Angeles','92034');

INSERT INTO EMPLOYEE VALUES('mk2','23','Josh','4082934932','01-JAN-15','manager');
INSERT INTO EMPLOYEE VALUES('m23','34','Derrick','4085820484','29-JAN-17','manager');
INSERT INTO EMPLOYEE VALUES('m29','12','Daniel','4085453454','10-JAN-16','manager');
INSERT INTO EMPLOYEE VALUES('msr','2','Jeremiah','4044039234','23-FEB-14','manager');

INSERT INTO EMPLOYEE VALUES('kfc2','23','Jason','4063434665','12-FEB-14','supervisor');
INSERT INTO EMPLOYEE VALUES('jmc2','23','John','4082923443','08-DEC-14','supervisor');
INSERT INTO EMPLOYEE VALUES('jk23','34','Sam','4082950383','08-APR-16','supervisor');
INSERT INTO EMPLOYEE VALUES('just1','34','Fred','4089684936','01-FEB-16','supervisor');
INSERT INTO EMPLOYEE VALUES('j323','34','Gary','4086972045','23-MAY-15','supervisor');
INSERT INTO EMPLOYEE VALUES('sbr','12','Minny','4063434665','20-OCT-15','supervisor');
INSERT INTO EMPLOYEE VALUES('lat','12','Don','4058335493','18-APR-14','supervisor');
INSERT INTO EMPLOYEE VALUES('hap','12','Kerry','4060456456','06-APR-16','supervisor');
INSERT INTO EMPLOYEE VALUES('jfp','2','Sue','4082945645','09-JAN-16','supervisor');
INSERT INTO EMPLOYEE VALUES('asr','2','Sandra','4082954845','10-JUL-15','supervisor');

INSERT INTO OWNER VALUES('ar15','Yoshi','1234567890','Rainbow Road','Outer Space',00000,0);
INSERT INTO OWNER VALUES('ar56','Donkey','6930596490','Jungle Japes','Jungle',12345,100);
INSERT INTO OWNER VALUES('cs12','Mario','6356456445','Somewhere','Milano',34933,150);
INSERT INTO OWNER VALUES('cs32','Luigi','7046766756','Somewhere Else','Milano',45463,50);
INSERT INTO OWNER VALUES('ar86','Toad','3564564565','Mario Circuit','Toad Cup',60365,200);
INSERT INTO OWNER VALUES('x86x','Peach','7934564564','Bowsers Castle','Rainbow Cup',45456,350);

INSERT INTO PROPERTY VALUES('5','ar15','just1','North Street','Santa Monica','26594',3,501.35,'available','10-APR-15');
INSERT INTO PROPERTY VALUES('6','ar15','j323','South Street','Santa Anna','69465',2,700.35,'available','12-APR-15');
INSERT INTO PROPERTY VALUES('7','ar56','jk23','What Street','Santa Anna','45645',1,500.28,'available','11-JUN-16');
INSERT INTO PROPERTY VALUES('8','ar56','jmc2','That Street','Fremont','42343',5,800.28,'available','11-DEC-15');
INSERT INTO PROPERTY VALUES('1','cs12','kfc2','Wonder Bread','Santa Monica','23432',6,1000.35,'available','10-APR-15');
INSERT INTO PROPERTY VALUES('2','cs32','kfc2','Top Kek Steet','Santa Anna','67567',8,650.28,'available','12-APR-15');
INSERT INTO PROPERTY VALUES('3','cs32','sbr','Red Brick Road','Santa Anna','87709',1,900.12,'available','11-JUN-16');
INSERT INTO PROPERTY VALUES('4','cs32','sbr','Yellow Brick Road','Fremont','56756',2,200.00,'available','11-DEC-15');
INSERT INTO PROPERTY VALUES('9','ar86','lat','Sesame Street','Santa Monica','98445',8,501.00,'available','10-APR-15');
INSERT INTO PROPERTY VALUES('10','ar86','hap','China Street','Santa Anna','46465',1,123.87,'available','12-APR-15');
INSERT INTO PROPERTY VALUES('11','x86x','jfp','Avenue Ave','Santa Anna','73233',9,876.99,'available','11-JUN-16');
INSERT INTO PROPERTY VALUES('12','x86x','asr','Road Unavailable','Fremont','26123',2,2000.09,'available','11-DEC-15');

INSERT INTO LEASE VALUES('5','23-MAR-16','12-DEC-16','Lilith','4089129047','4089381748','Mira','4084945984',501.35,50.00,'Fred');
INSERT INTO LEASE VALUES('6','20-MAY-16','09-DEC-16','Lily','4080646065','4084065656','Mia','4083454984',700.35,50.00,'Gary');
INSERT INTO LEASE VALUES('7','01-JAN-16','01-JUL-16','Lily','4080646065','4084065656','Tellius','906756756',560.35,50.00,'Sam');
INSERT INTO LEASE VALUES('1','31-JUL-16','12-APR-17','Davis','3453453554','6384939756','Sim','5678396456',1000.35,100.00,'Jason');
INSERT INTO LEASE VALUES('2','15-JUN-16','10-APR-17','Henry','3205890356','9467845667','Seth','6304536675',650.28,200.00,'Jason');
