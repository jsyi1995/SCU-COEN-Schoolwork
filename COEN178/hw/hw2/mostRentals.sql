CREATE OR REPLACE FUNCTION mostRentals
RETURN CHAR IS 
	ret CHAR(100);
	first Customer.first_name%type;
	last Customer.last_name%type;
	pnumber Customer.phone%type;
BEGIN 
	SELECT first_name INTO first
	FROM Customer
	WHERE custID IN
	(
		SELECT x.custID
		FROM 
		(
			SELECT u.custID, COUNT(*) AS freq, 
			RANK() OVER (ORDER BY COUNT(*) DESC) AS rank
 	 		FROM Rental u
 	 		GROUP BY u.custID
		) x
	   	WHERE x.rank = 1
	);

	SELECT last_name INTO last
	FROM Customer
	WHERE custID IN
	(
		SELECT x.custID
		FROM 
		(
			SELECT u.custID, COUNT(*) AS freq, 
			RANK() OVER (ORDER BY COUNT(*) DESC) AS rank
 	 		FROM Rental u
 	 		GROUP BY u.custID
		) x
	   	WHERE x.rank = 1
	);

	SELECT phone INTO pnumber
	FROM Customer
	WHERE custID IN
	(
		SELECT x.custID
		FROM 
		(
			SELECT u.custID, COUNT(*) AS freq, 
			RANK() OVER (ORDER BY COUNT(*) DESC) AS rank
 	 		FROM Rental u
 	 		GROUP BY u.custID
		) x
	   	WHERE x.rank = 1
	);

	IF sql%notfound THEN
		ret:='no customer entries found';
		RETURN ret;
	ELSIF sql%found THEN
		ret:= first || ' ' || last || ' ' || pnumber;
		RETURN ret;

	END IF;
END;
/
show errors;
