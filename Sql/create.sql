CREATE TABLE mytable (
    -- int 类型，不为空，自增
    id   INT      NOT NULL AUTO_INCREMENT,
    -- int 类型，不可为空，默认值为 1，不为空
    col1 INT      NOT NULL DEFAULT 1,
    -- 变长字符串类型，最长为 45 个字符，可以为空
    col2 VARCHAR(45) NULL,
    -- 日期类型，可为空
    col3 DATE        NULL,
    -- 设置主键为 id
    PRIMARY KEY id
    );
