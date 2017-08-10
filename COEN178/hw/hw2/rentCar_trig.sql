CREATE OR REPLACE TRIGGER rentCar_trig
AFTER INSERT
	ON Rental
	FOR EACH ROW
BEGIN
	UPDATE Car c
	SET c.status = 'out'
	WHERE c.carID = :new.carID;
	
END;
/
show errors;