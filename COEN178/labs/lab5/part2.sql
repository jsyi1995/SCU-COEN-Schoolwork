CREATE OR REPLACE PROCEDURE changeCity
AS
	total_rows number(2);
BEGIN
	UPDATE Cust_5
	SET city='LA'
	WHERE city='SJ';

	IF sql%notfound THEN
		dbms_output.put_line('no customers selected');
	ELSIF sql%found THEN
		total_rows := sql%rowcount;
		dbms_output.put_line( total_rows || 'customers selected and updated');
	END IF;
END;
/
show errors;
