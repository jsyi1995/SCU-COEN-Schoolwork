DROP TABLE Order_5;
DROP TABLE Cust_5;

CREATE TABLE Cust_5 (
	custno VARCHAR(5) PRIMARY KEY,
	custname VARCHAR(20),
	city VARCHAR(20)
);

CREATE TABLE Order_5 (
	orderno VARCHAR(5) PRIMARY KEY,
	amount NUMBER(10, 2),
	custno VARCHAR(5),
	CONSTRAINT order_fkey
		FOREIGN Key (custno)
		REFERENCES Cust_5(custno)
);

CREATE TABLE DeletedOrder (
	orderno VARCHAR(5),
	amount NUMBER(10,2)
);


INSERT INTO Cust_5 VALUES('c1','Smith','SJ');
INSERT INTO Cust_5 VALUES('c2','Jones','SJ');
INSERT INTO Cust_5 VALUES('c3','Peters','SFO');
INSERT INTO Cust_5 VALUES('c20','Chen','LA');
INSERT INTO Cust_5 VALUES('c33','Williams','SFO');


INSERT INTO Order_5 VALUES('o90',2000.00,'c1');
INSERT INTO Order_5 VALUES('o91',4000.00,'c1');
INSERT INTO Order_5 VALUES('o92',12000.00,'c1');
INSERT INTO Order_5 VALUES('o55',1000.00,'c2');
INSERT INTO Order_5 VALUES('o56',2000.00,'c2');
INSERT INTO Order_5 VALUES('o77',44000.00,'c20');

COMMIT;



