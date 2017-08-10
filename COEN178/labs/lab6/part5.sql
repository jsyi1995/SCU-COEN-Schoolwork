CREATE OR REPLACE TRIGGER update_accounts_trig
	AFTER INSERT ON billpay_6
	FOR EACH ROW
BEGIN
	UPDATE accounts_6
	SET amount = amount - :new.amount
	WHERE accountno = :new.accountno;
END update_accounts_trig;
/
show errors;
