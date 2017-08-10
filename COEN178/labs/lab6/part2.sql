CREATE OR REPLACE TRIGGER display_account_trig
	AFTER INSERT ON accounts_6 
	FOR EACH ROW 
BEGIN
	DBMS_output.put_line('Account number: ' || :new.accountno 
	|| ' Account type: ' || :new.accounttype || ' Amount: ' || 
	:new.amount || ' Customer number: ' || :new.custno);

END;
/
show errors;
