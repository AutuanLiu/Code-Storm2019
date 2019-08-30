// 打印从1到最大的n位数
#include <iostream>
#include <string>

using namespace std;

// 不输出前面多余的 '0'
void print(string number)
{
    int n = number.size();
    bool start = true, doing = false;
    for (int i = 0; i < n; i++) {
        if (start && number[i] != '0') {
            start = false;
        }
        if (!start) {
            cout << number[i];
            doing = true;
        }
    }
    if (doing)
        cout << endl;
}

// 递归调用或者理解为回溯（循环结束）
void print_digits(string number, int n, int index)
{
    if (index == n) {
        print(number);
        return;
    }

    //  当前位循环0~9
    for (int i = 0; i < 10; i++) {
        number[index] = i + '0';
        print_digits(number, n, index + 1);
    }
}

int main(void)
{
    int n; // n 大于 0
    string number(n, '0');
    print_digits(number, n, 0);
    return 0;
}
