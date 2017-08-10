DROP TABLE Shipment;
DROP TABLE Supplier;
DROP TABLE Parts;

CREATE TABLE Supplier (
  sno VARCHAR(5) PRIMARY KEY,
  sname VARCHAR(15),
  city VARCHAR(10)
);

CREATE TABLE Parts (
  pno VARCHAR(5) PRIMARY KEY,
  pname VARCHAR(15),
  color VARCHAR(10),
  price NUMERIC(5,2)
);

CREATE TABLE Shipment (
  sno VARCHAR(5),
  pno VARCHAR(5),
  quantity INTEGER,
  PRIMARY KEY (sno, pno),
  FOREIGN KEY (sno)
    REFERENCES Supplier (sno),
  FOREIGN KEY (pno)
    REFERENCES Parts (pno)
);

INSERT INTO Parts VALUES ('p1','hammer','black',10.50);
INSERT INTO Parts VALUES ('p2','nut','blue',3.75);
INSERT INTO Parts VALUES ('p3','bolt','blue',1.75);
INSERT INTO Parts VALUES ('p4','wrench','white',5.00);
INSERT INTO Parts VALUES ('p5','coil','black',7.25);

INSERT INTO Supplier VALUES ('s1','Smith','San Jose');
INSERT INTO Supplier VALUES ('s2','Jones','San Jose');

INSERT INTO Shipment VALUES ('s1','p1',100);
INSERT INTO Shipment VALUES ('s2','p2',50);
INSERT INTO Shipment VALUES ('s2','p3',300);
INSERT INTO Shipment VALUES ('s1','p4',75);
INSERT INTO Shipment VALUES ('s1','p5',20);

