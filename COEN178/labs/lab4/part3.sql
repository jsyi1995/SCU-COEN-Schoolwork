--
-- Exercise 5
--


-- A PLSQL block of code to extract Customer Name,city and display them.
set serveroutput on
DECLARE
	-- Variable Declarations
	l_name Cust_5.custname%type;
	l_city Cust_5.city%type;
-- executable part from BEGIN to END

BEGIN
	SELECT custname, city
		INTO l_name, l_city
	FROM CUST_5
	where custno = 'c1';
	-- output the result
	DBMS_OUTPUT.PUT_LINE('Customer Name = '|| l_name);
	DBMS_OUTPUT.PUT_LINE('City = '|| l_city);
END;
/
SHOW errors;


--
-- What does the above procedure produce? Perhaps nothing?
--

-- "PL/SQL procedure successfully completed."
-- "No errors."

-- Add 'set serveroutput on' to the beginning of this script.
-- Now, what does the above procedure produce?
--
