-- 把具有相同的数据值的行放在同一组中。
-- 可以对同一分组数据使用汇总函数进行处理，例如求分组数据的平均值等。
-- 指定的分组字段除了能按该字段进行分组，也会自动按该字段进行排序。

SELECT col, COUNT(*) AS num
FROM mytable
GROUP BY col;

-- GROUP BY 自动按分组字段进行排序，ORDER BY 也可以按汇总字段来进行排序。

SELECT col, COUNT(*) AS num
FROM mytable
GROUP BY col
ORDER BY num;

-- WHERE 过滤行，HAVING 过滤分组，行过滤应当先于分组过滤。

SELECT col, COUNT(*) AS num
FROM mytable
WHERE col > 2
GROUP BY col
HAVING num >= 2;

-- GROUP BY 子句出现在 WHERE 子句之后，ORDER BY 子句之前；
-- 除了汇总字段外，SELECT 语句中的每一字段都必须在 GROUP BY 子句中给出；
-- NULL 的行会单独分为一组；
-- 大多数 SQL 实现不支持 GROUP BY 列具有可变长度的数据类型。