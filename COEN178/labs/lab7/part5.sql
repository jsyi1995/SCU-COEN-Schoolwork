SET PAGESIZE 100
SET LINESIZE 79 
PROMPT **************************************************************** 

PROMPT Generating the Report 
TTITLE CENTER 'Expense Report' 
SET UNDERLINE =
BREAK ON ROW SKIP 1

BREAK ON REPORT
  COMPUTE AVG SUM MAX OF groceries ON REPORT
BREAK ON REPORT
  COMPUTE AVG SUM MAX OF entertainment ON REPORT
BREAK ON REPORT
  COMPUTE AVG SUM MAX OF rent ON REPORT

COLUMN expenseDate    HEADING 'Date'
COLUMN groceries      HEADING 'Groceries'
COLUMN entertainment  HEADING 'Entertainment'
COLUMN rent           HEADING 'Rent'
    
COLUMN groceries     FORMAT $99999.99     	
COLUMN entertainment FORMAT $99999.99
COLUMN rent          FORMAT $99999.99

SELECT expenseDate, groceries, entertainment, rent
  FROM expenses;