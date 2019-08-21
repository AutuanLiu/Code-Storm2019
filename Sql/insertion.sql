-- 插入修改
-- 普通插入
INSERT INTO mytable(col1, col2)
VALUES(val1, val2);

-- 插入检索出来的数据
INSERT INTO mytable1(col1, col2)
SELECT col1, col2
FROM mytable2;

-- 将一个表的内容插入到一个新表
CREATE TABLE newtable AS
SELECT *
FROM mytable;
