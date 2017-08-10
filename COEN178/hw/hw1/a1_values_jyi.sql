INSERT INTO Car VALUES ('a1','toyota prius', 2005, 'sedan', 'available');
INSERT INTO Car VALUES ('b2','toyota sienna', 2008, 'van', 'available');
INSERT INTO Car VALUES ('d4','acura mdx', 2014, 'suv', 'available');
INSERT INTO Car VALUES ('s3','tesla model x', 2016, 'suv', 'available');
INSERT INTO Car VALUES ('x3','chevy volt', 2014, 'sedan', 'out');
INSERT INTO Car VALUES ('y7','tesla model 3', 2015, 'sedan', 'available');
INSERT INTO Car VALUES ('z8','toyota camry', 2003, 'sedan', 'out');

INSERT INTO Customer VALUES ('asdf','John', 'Smith', 4081234567);
INSERT INTO Customer VALUES ('sdfs','Mary', 'Jones', 4083564566);
INSERT INTO Customer VALUES ('werb','Vincent', 'Chen', 4086589564);
INSERT INTO Customer VALUES ('mddgf','Greg', 'King', 4081294093);
INSERT INTO Customer VALUES ('rtyr','James', 'Bond', 4082509475);
INSERT INTO Customer VALUES ('wker','Susan', 'Blogg', 4082343963);
INSERT INTO Customer VALUES ('fcx','Jordan', 'Lai', 4086829376);
INSERT INTO Customer VALUES ('tkyn','Josh', 'Yi', 4086839434);

INSERT INTO Rental VALUES ('a1','asdf', TO_DATE('2014-01-21','yyyy/mm/dd'), TO_DATE('2014-03-14', 'yyyy/mm/dd'));
INSERT INTO Rental VALUES ('d4','werb', TO_DATE('2015-07-12','yyyy/mm/dd'), TO_DATE('2015-08-15', 'yyyy/mm/dd'));
INSERT INTO Rental VALUES ('a1','asdf', TO_DATE('2015-09-09','yyyy/mm/dd'), TO_DATE('2015-12-15', 'yyyy/mm/dd'));
INSERT INTO Rental VALUES ('s3','asdf', TO_DATE('2016-10-24','yyyy/mm/dd'), TO_DATE('2016-11-02', 'yyyy/mm/dd'));
INSERT INTO Rental VALUES ('y7','tkyn', TO_DATE('2016-11-12','yyyy/mm/dd'), TO_DATE('2016-11-15', 'yyyy/mm/dd'));
INSERT INTO Rental VALUES ('y7','fcx', TO_DATE('2017-01-09','yyyy/mm/dd'), TO_DATE('2017-01-12', 'yyyy/mm/dd'));
INSERT INTO Rental VALUES ('y7','asdf', TO_DATE('2017-01-14','yyyy/mm/dd'), TO_DATE('2017-01-21', 'yyyy/mm/dd'));
