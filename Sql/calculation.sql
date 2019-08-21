-- 计算字段通常需要使用 AS 来取别名，否则输出的时候字段名为计算表达式

SELECT col1 * col2 AS alias
FROM mytable;

-- CONCAT() 用于连接两个字段。许多数据库会使用空格把一个值填充为列宽，
-- 因此连接的结果会出现一些不必要的空格，使用 TRIM() 可以去除首尾空格

SELECT CONCAT(TRIM(col1), '(', TRIM(col2), ')') AS concat_col
FROM mytable;
