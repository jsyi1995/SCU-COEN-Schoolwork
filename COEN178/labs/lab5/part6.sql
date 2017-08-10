CREATE OR REPLACE PROCEDURE change_amount
	(orderno_param IN ORDER_5.orderno%type,
	new_amt IN ORDER_5.amount%type)
AS
	BEGIN
		UPDATE ORDER_5
		SET amount = new_amt
		WHERE orderno = orderno_param;
	END change_amount;
/
show errors;
