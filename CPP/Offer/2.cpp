class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        int newlength = 0;
        int oldlength = 0;
        int j = 0;
        while (str[j])
        {
            newlength++;
            oldlength++;
            if (str[j] == ' ')
                newlength += 2;
            j++;
        }
        if (newlength > length)
            return;
        str[newlength] = 0;
        for (int i = oldlength - 1, j = newlength - 1; i >= 0; i--, j--)
        {
            if (str[i] == ' ')
            {
                str[j] = '0';
                str[j - 1] = '2';
                str[j - 2] = '%';
                j = j - 2;
            }
            else
                str[j] = str[i];
        }
    }
};

class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        int bankNumber = 0;

        int i = 0;

        for (; str[i] != '\0'; ++i)
        {
            if (str[i] == ' ')
            {
                ++bankNumber;
            }
        }

        int totalNumber = i + 1 + bankNumber * 2;

        int pos = totalNumber - 1;

        for (; i >= 0; --i)
        {
            if (str[i] == ' ')
            {
                str[pos--] = '0';
                str[pos--] = '2';
                str[pos--] = '%';
            }
            else
            {
                str[pos--] = str[i];
            }
        }
    }
};

class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        if (str == NULL || length <= 0)
            return;
        int len = 0;
        int count = 0;
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] == ' ')
                count++;
            len++;
            i++;
        }

        int newlen = len + count * 2;
        if (length < newlen)
            return;
        int a = len;
        int b = newlen;
        while (a >= 0 && b >= 0)
        {
            if (str[a] == ' ')
            {
                str[b--] = '0';
                str[b--] = '2';
                str[b--] = '%';
            }
            else
            {
                str[b] = str[a];
                b--;
            }
            a--;
        }
        return;
    }
};

class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        if (str == NULL || length < 0)
            return;
        int orignallength = 0;
        int countofbalnk = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            orignallength++;
            if (str[i] == ' ')
                countofbalnk++;
        }
        int newlength = orignallength + countofbalnk * 2; //插入后的长度

        //char *str2 = (char *)malloc(sizeof(char)*newlength);
        ////char *str2 = new char[orignallength + 2 * countofblank];
        //for(int i=0,j=0;str[i]!='\0';i++)
        //{
        //    if(str[i]==' '){
        //        str2[j]='%';
        //        str2[j+1]='2';
        //        str2[j+2]='0';
        //        j=j+3;
        //    }
        //    else{
        //        str2[j]=str[i];
        //        j++;
        //    }
        //}
        //str=str2;

        int pOrignallength = orignallength;
        int pNewlength = newlength;
        while (pOrignallength >= 0 && pNewlength > pOrignallength)
        {
            if (str[pOrignallength] == ' ')
            {
                str[pNewlength--] = '0';
                str[pNewlength--] = '2';
                str[pNewlength--] = '%';
            }
            else
            {
                str[pNewlength--] = str[pOrignallength];
            }
            pOrignallength--;
        }
    }
};

class Solution
{
  public:
    void replaceSpace(char *str, int length)
    {
        if (str == NULL)
            return;
        int CountOfBlanks = 0;
        int Originallength = 0;
        for (int i = 0; str[i] != '\0'; i++)
        {
            Originallength++;
            if (str[i] == ' ')
                ++CountOfBlanks;
        }
        int len = Originallength + 2 * CountOfBlanks;
        if (len + 1 > length)
            return;

        char *pStr1 = str + Originallength; //复制结束符‘\0’
        char *pStr2 = str + len;
        while (pStr1 < pStr2)
        {
            if (*pStr1 == ' ')
            {
                *pStr2-- = '0';
                *pStr2-- = '2';
                *pStr2-- = '%';
            }
            else
            {
                *pStr2-- = *pStr1;
            }
            --pStr1;
        }
    }
};
