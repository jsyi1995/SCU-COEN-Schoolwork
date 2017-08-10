CREATE OR REPLACE FUNCTION getAmountForOrder
	(orderno_param IN ORDER_5.orderno%type)
RETURN CHAR IS 
	ret CHAR(100);
	amt ORDER_5.amount%type;
BEGIN 
	SELECT amount INTO amt
	FROM ORDER_5
	WHERE orderno=orderno_param;

	IF sql%notfound THEN
		ret:='no orders selected';
		RETURN ret;
	ELSIF sql%found THEN
		ret:=' amount for ' || orderno_param || ' is ' || amt;
		RETURN ret;
	END IF;
END;
/
show errors;
