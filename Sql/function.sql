-- 函 数	   说 明
-- AVG()	返回某列的平均值
-- COUNT()	返回某列的行数
-- MAX()	返回某列的最大值
-- MIN()	返回某列的最小值
-- SUM()	返回某列值之和
-- AVG()   会忽略 NULL 行。

-- 使用 DISTINCT 可以汇总不同的值。

SELECT AVG(DISTINCT col1) AS avg_col
FROM mytable;