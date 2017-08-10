CREATE OR REPLACE TRIGGER orders_cancelled_trig
AFTER DELETE 
	ON ORDER_5
	FOR EACH ROW
BEGIN
	INSERT INTO DeletedOrder
		VALUES(:old.orderno, :old.amount);
END;
/
show errors;
