DROP TABLE expenses;

CREATE TABLE expenses (
  expenseDate DATE PRIMARY KEY,
  groceries NUMBER(10,2),
  entertainment NUMBER(10,2),
  rent Number(10,2)
);

INSERT INTO expenses VALUES ('12-Mar-2015', 15.25, 10.50, 500.00);
INSERT INTO expenses VALUES ('15-Nov-2016', 25.75, 5.00, 700.00);
INSERT INTO expenses VALUES ('27-Jan-2014', 10.00, 12.00, 400.00);
INSERT INTO expenses VALUES ('20-Feb-2015', 12.00, 15.00, 800.00);
INSERT INTO expenses VALUES ('30-Oct-2014', 5.00, 2.00, 100.00);







