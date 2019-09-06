-- https://docs.microsoft.com/en-us/learn/modules/get-started-xpp-dynamics-365-finance-operations/4-sql
Select [FindOptions] [FieldList]
from [Table] [Options]
[OrderByClause]
[WhereClause]
[JoinClause]


SELECT col_name, ...
FROM table_name
WHERE where_condition
GROUP BY col_name,...
HAVING where_condition
ORDER BY col_name,...
 LIMIT offset,row_count

INSERT INTO table_name
    (col_name,...)
values(expr, ...)

UPDATE table_name SET col_name=expr,... WHERE where_condition

DELETE FROM table_name WHERE where_condition

REPLACE
INTO table_name
(col_name,...) values
(expr,...)