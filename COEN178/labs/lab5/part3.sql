CREATE OR REPLACE PROCEDURE showOrdersByAmount
	(amount_param IN ORDER_5.amount%type)
AS
	CURSOR amt_cur IS
	SELECT *
	FROM ORDER_5
	WHERE amount > amount_param;
	amt_rec amt_cur%rowtype; -- local variable
	BEGIN 
		IF NOT amt_cur%ISOPEN THEN
			OPEN amt_cur;
		END IF;
		LOOP
			FETCH amt_cur INTO amt_rec;
			EXIT WHEN amt_cur%NOTFOUND;
			dbms_output.put_line(amt_rec.orderno || ' ' ||amt_rec.amount);
		END LOOP;
		CLOSE amt_cur; --close the cursor
	END;
	/
	show errors;
