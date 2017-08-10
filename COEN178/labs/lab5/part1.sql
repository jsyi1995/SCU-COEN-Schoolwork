CREATE OR REPLACE PROCEDURE increaseAmount
AS
	total_rows number(2);
BEGIN 
	UPDATE ORDER_5
	SET amount = amount + 200;

	IF sql%notfound THEN
		dbms_output.put_line('no orders selected');
	ELSIF sql%found THEN
		total_rows :=sql%rowcount;
		dbms_output.put_line(total_rows || 'orders selected and updated');
	END IF;
END;

/
show errors;
