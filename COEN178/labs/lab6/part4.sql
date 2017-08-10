CREATE OR REPLACE TRIGGER update_totals
	AFTER INSERT OR
		  DELETE OR
		  UPDATE
	ON accounts_6

DECLARE 
	CURSOR s_stats IS
		SELECT custno, SUM(accounts_6.amount) AS amt
		FROM accounts_6
		GROUP BY custno;

BEGIN 
	FOR v_rec in s_stats
	LOOP
		UPDATE totals_6
		SET totalamount = v_rec.amt
		WHERE v_rec.custno = custno;
	END LOOP;

END update_totals;
/
show errors;
