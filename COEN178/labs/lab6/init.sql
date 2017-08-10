
DROP TABLE billpay_6;
DROP TABLE totals_6;
DROP TABLE accounts_6;
DROP TABLE bankcust_6;

CREATE TABLE bankcust_6 (
	custno VARCHAR(5) PRIMARY KEY,
	custname VARCHAR(20),
	street VARCHAR(30),
	city VARCHAR(20)
);


CREATE TABLE accounts_6 (
	accountno VARCHAR(5) PRIMARY KEY,
	accounttype VARCHAR(10),
	amount NUMBER(10, 2),
	custno VARCHAR(5),
	CONSTRAINT accounts_fkey 
		FOREIGN KEY (custno)
			REFERENCES bankcust_6 (custno)
);


CREATE TABLE totals_6 (
	custno VARCHAR(5),
	totalamount NUMBER(10,2),
	CONSTRAINT totals_fkey
		FOREIGN KEY (custno)
			REFERENCES bankcust_6 (custno)
);

CREATE TABLE billpay_6 (
  billno VARCHAR(5),
  custno VARCHAR(5),
  accountno VARCHAR(5),
  amount NUMBER(10,2),
  CONSTRAINT billpay_fkey1
    FOREIGN KEY (custno)
      REFERENCES bankcust_6 (custno),
  CONSTRAINT billpay_fkey2
    FOREIGN KEY (accountno)
      REFERENCES accounts_6 (accountno)
);


