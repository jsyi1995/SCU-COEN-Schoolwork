SET PAGESIZE 100
SET LINESIZE 79 
PROMPT **************************************************************** 

PROMPT Generating the Report 

SET TERMOUT OFF
COLUMN curdate NEW_VALUE report_date 
SELECT TO_CHAR(SYSDATE,'dd-Mon-yyyy') curdate
FROM DUAL; 
SET TERMOUT ON

PROMPT &report_date 



TTITLE skip 2 CENTER 'Name and City of BankCust' skip 2

COLUMN custname HEADING 'Name' FORMAT A18
COLUMN city HEADING 'City' FORMAT A10 

SELECT custname, city
FROM bankcust_6;


