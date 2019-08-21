-- 相同值只会出现一次。它作用于所有列，也就是说所有列的值都相同才算相同。
SELECT DISTINCT col1, col2
FROM mytable;

-- 限制返回的行数。
-- 可以有两个参数，第一个参数为起始行，从 0 开始；第二个参数为返回的总行数。
-- 返回前 5 行
SELECT *
FROM mytable
LIMIT 5;


SELECT *
FROM mytable
LIMIT 0, 5;

-- 返回 3-5 行
SELECT *
FROM mytable
LIMIT 2, 3;
