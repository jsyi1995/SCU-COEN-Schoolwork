CREATE OR REPLACE TRIGGER display_account_trig_full
	AFTER INSERT ON accounts_6 
	FOR EACH ROW
DECLARE 
	name bankcust_6.custname%type;
	custcity bankcust_6.city%type;	
BEGIN
	DBMS_output.put_line('Account number: ' || :new.accountno
	|| ' Account type: ' || :new.accounttype || ' Amount: ' || 
	:new.amount || ' Customer number: ' || :new.custno);
	
	
	SELECT custname INTO name
	FROM bankcust_6
	WHERE custno = :new.custno;
	
	SELECT city INTO custcity
	FROM bankcust_6
	WHERE custno = :new.custno;

	DBMS_output.put_line(' Customer Name: ' || name || ' City: ' || custcity);

END display_account_trig_full;
/
show errors;
