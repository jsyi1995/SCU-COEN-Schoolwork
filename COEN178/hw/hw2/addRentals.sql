CREATE OR REPLACE PROCEDURE addARental
	(p_carId IN Car.carId%type,
	p_custId IN Customer.custId%type)
	
IS
	x NUMBER:=0;
BEGIN
	SELECT nvl(
		(
			SELECT 1 
			FROM Car 
			WHERE carID = p_carID AND status = 'available'
		) , 0) INTO x FROM DUAL;
	IF (x = 0) THEN
		dbms_output.put_line ('car is not available');
	ELSE
		INSERT INTO Rental (carID, custId, date_rented)
		VALUES (p_carId, p_custId, SYSDATE);
		dbms_output.put_line ('values inserted');		
	END IF;

END addARental;
/
SHOW errors;
