CREATE OR REPLACE TRIGGER insert_total_trig
	AFTER INSERT ON bankcust_6
	FOR EACH ROW
BEGIN
	INSERT INTO totals_6
	VALUES (:new.custno, 00.00);
END insert_total_trig;
/
show errors;
