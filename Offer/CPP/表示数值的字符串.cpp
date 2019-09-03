// 表示数值的字符串
class Solution {
public:
    bool isNumeric(char* string)
    {
        if (string == nullptr)
            return false;
        bool isnum = isInteger(&string); // 如果包含正负号、正负号后面是否有数字
        
        // 如果以小数点开头
        if (*string == '.') {
            ++string;
            // 小数点后面是否有数字
            // 或操作是因为 .123 12. 都是合法的
            isnum = isUnsigned(&string) || isnum;
        }

        // 如果以 e 或者 E 开头，则后面必须包含数字
        if (*string == 'e' || *string == 'E') {
            ++string;
            isnum = isInteger(&string) && isnum;
        }
        return isnum && *string == '\0';
    }

    // 正负号后面是否包含若干数字
    bool isInteger(char** string)
    {
        if (**string == '+' || **string == '-')
            ++(*string);
        return isUnsigned(string);
    }

    // 字符串中是否存在若干数字
    bool isUnsigned(char** string)
    {
        char* before = *string;
        while (**string != '\0' && **string >= '0' && **string <= '9')
            ++(*string);
        return *string > before;
    }
};