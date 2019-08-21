-- 使用更新和删除操作时一定要用 WHERE 子句，不然会把整张表的数据都破坏。可以先用
-- SELECT 语句进行测试，防止错误删除
DELETE FROM mytable
WHERE id = 1;

-- TRUNCATE TABLE 可以清空表，也就是删除所有行
TRUNCATE TABLE mytable;
