DROP TABLE Employee CASCADE CONSTRAINTS;
DROP TABLE Department CASCADE CONSTRAINTS;

CREATE TABLE Employee(
  empid char(10) PRIMARY KEY,
  ename char(20)
);

-- Part B

CREATE TABLE Department(
  empid char(10) NOT NULL,
  deptid char(20) PRIMARY KEY,
  dname char(20),
  FOREIGN KEY (empid) REFERENCES Employee(empid) ON DELETE CASCADE
);
