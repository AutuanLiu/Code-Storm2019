// 给出Excel的列号如AB给出对应的数字行号
#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 26进制
long long getRow(string& s)
{
    int pos = 0, n = s.size();
    long long ret = 0;
    if (n == 0)
        return 0;
    for (int i = n - 1; i >= 0; i--) {
        int num = s[i] - 'A' + 1;
        assert(num > 0 && num <= 26);
        ret += num * (long long)pow(26, pos);
        pos++;
    }
    return ret;
}

int main(void)
{
    vector<string> ss{ "AB", "ABC", "DEF", "ERTGH", "IYT", "YES" };
    for (string& s : ss) {
        cout << getRow(s) << endl;
    }
    return 0;
}