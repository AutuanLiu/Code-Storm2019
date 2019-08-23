-- 连接用于连接多个表，使用 JOIN 关键字，并且条件语句使用 ON 而不是 WHERE。
-- 连接可以替换子查询，并且比子查询的效率一般会更快。
-- 可以用 AS 给列名、计算字段和表名取别名，给表名取别名是为了简化 SQL 语句以及连接相同表。

-- 内连接
-- 内连接又称等值连接，使用 INNER JOIN 关键字。

SELECT A.value, B.value
FROM tablea AS A INNER JOIN tableb AS B
ON A.key = B.key;

-- 可以不明确使用 INNER JOIN，而使用普通查询并在 WHERE 中将两个表中要连接的列用等值方法连接起来。

SELECT A.value, B.value
FROM tablea AS A, tableb AS B
WHERE A.key = B.key;

-- 自连接
-- 自连接可以看成内连接的一种，只是连接的表是自身而已。
-- 一张员工表，包含员工姓名和员工所属部门，要找出与 Jim 处在同一部门的所有员工姓名。
-- 子查询版本

SELECT name
FROM employee
WHERE department = (
      SELECT department
      FROM employee
      WHERE name = "Jim");

-- 自连接版本

SELECT e1.name
FROM employee AS e1 INNER JOIN employee AS e2
ON e1.department = e2.department
      AND e2.name = "Jim";
    
-- 自然连接
-- 自然连接是把同名列通过等值测试连接起来的，同名列可以有多个。
-- 内连接和自然连接的区别：内连接提供连接的列，而自然连接自动连接所有同名列。


SELECT A.value, B.value
FROM tablea AS A NATURAL JOIN tableb AS B;

-- 外连接
-- 外连接保留了没有关联的那些行。分为左外连接，右外连接以及全外连接，左外连接就是保留左表没有关联的行。
-- 检索所有顾客的订单信息，包括还没有订单信息的顾客。

SELECT Customers.cust_id, Orders.order_num
FROM Customers LEFT OUTER JOIN Orders
ON Customers.cust_id = Orders.cust_id;
