CREATE OR REPLACE TRIGGER no_update_pk_trig
	AFTER UPDATE ON bankcust_6
	FOR EACH ROW
BEGIN
	IF UPDATING ('custno') THEN
		RAISE_APPLICATION_ERROR(-20999, 'forbidden pk update');
	END IF;
END;
/
show errors;