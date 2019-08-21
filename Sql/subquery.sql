-- 子查询中只能返回一个字段的数据
-- 可以将子查询的结果作为 WHRER 语句的过滤条件

SELECT *
FROM mytable1
WHERE col1 IN (SELECT col2
               FROM mytable2);

-- 检索出客户的订单数量，子查询语句会对第一个查询检索出的每个客户执行一次
SELECT cust_name, (SELECT COUNT(*)
                   FROM Orders
                   WHERE Orders.cust_id = Customers.cust_id)
                   AS orders_num
FROM Customers
ORDER BY cust_name;
