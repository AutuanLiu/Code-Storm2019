-- 函数	       说明
-- LEFT()	    左边的字符
-- RIGHT()	    右边的字符
-- LOWER()	    转换为小写字符
-- UPPER()	    转换为大写字符
-- LTRIM()	    去除左边的空格
-- RTRIM()	    去除右边的空格
-- LENGTH()	    长度
-- SOUNDEX()	转换为语音值

-- 其中， SOUNDEX() 可以将一个字符串转换为描述其语音表示的字母数字模式。

SELECT *
FROM mytable
WHERE SOUNDEX(col1) = SOUNDEX('apple')
