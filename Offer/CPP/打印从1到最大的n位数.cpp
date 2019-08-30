// 打印从1到最大的n位数
#include <iostream>
#include <string>
using namespace std;

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
        cout << "\t";
}

void print_digits(string number, int length, int index)
{
    if (index == length - 1) {
        print(number);
        return;
    }

    //  当前位循环0~9
    for (int i = 0; i < 10; i++) {
        number[index + 1] = i + '0';
        print_digits(number, length, index + 1);
    }
}

void get_digits(int n)
{
    if (n <= 0)
        return;

    string number(n, '0');

    //  最地位循环0~9
    for (int i = 0; i < 10; i++) {
        number[0] = i + '0';
        print_digits(number, n, 0);
    }
}

int main(void)
{
    int n;

    while (cin >> n) {
        get_digits(n);
    }
    return 0;
}