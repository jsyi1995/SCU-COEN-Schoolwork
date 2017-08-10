CREATE OR REPLACE PROCEDURE showCustWithLargeOrders
	(amount_param IN ORDER_5.amount%type)
AS
	CURSOR large_cur IS
	SELECT custname, city
	FROM CUST_5 
	WHERE custno 
	IN (SELECT custno 
		FROM ORDER_5
		WHERE amount > amount_param);
	result_rec large_cur%rowtype; --local var
	BEGIN 
		IF NOT large_cur%ISOPEN THEN
			OPEN large_cur;
		END IF;
		LOOP
			FETCH large_cur INTO result_rec;
			EXIT WHEN large_cur%NOTFOUND;
			dbms_output.put_line(result_rec.custname || ' ' || result_rec.city);
		END LOOP;
		CLOSE large_cur; --close the cursor
	END;
	/
	show errors;
