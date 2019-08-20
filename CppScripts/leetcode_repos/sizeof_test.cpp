//https://www.jianshu.com/p/e4685bb2e2f3

#include <iostream>
#include "leetcode_repos.h"

#pragma pack(push, 1)  // 将对齐系数1压入internal compiler stack，同时设置当前的packing alignment为1
#pragma pack(push, 4)  // 将4也压入栈，同时设置当前的packing alignment为4
#pragma pack(show)    // 显示当前packing alignment的字节数
#pragma pack(pop)     // 弹出internal compiler stack顶端的一条记录，这里弹出了4
#pragma pack(show)   // 此时顶端的packing alignment值为1,

struct test
{
	char m1;
	short m2;
	int m3;
};

#pragma pack()  // 更改为缺省值8 
#pragma pack(show)

struct test1
{
	char c;
	short s1;
	short s2;
	int i;
};

// 定义对齐方式 4 位
#pragma pack(4)
using namespace std;

struct B {
	float a;
	short b[3];
	char* cp[2];
};

#pragma pack(push, 1) // 不对齐 对齐为 1
struct stu {
	char sex;
	int length;
	char name[10];
};

#pragma pack() // 4
struct stu1 {
	char sex;
	int length;
	char name[10];
};

struct stu3 {
	char sex;
	int length;
	char name[3];
};


int main()
{
	B b;
	struct stu my_stu;
	struct stu1 my_stu1;
	struct stu3 my_stu3;
	float a;
	int x;
	short y;
	double z;
	long x1;
	long long x2;
	cout << sizeof(a) << endl;
	cout << sizeof(x) << endl;
	cout << sizeof(y) << endl;
	cout << sizeof(z) << endl;
	cout << sizeof(x1) << endl;
	cout << sizeof(x2) << endl;

	char* cp[2];
	cout << sizeof(cp) << endl;  // 64 位系统
	cout << sizeof(b) << endl;
	cout << sizeof(my_stu) << endl;
	cout << sizeof(my_stu1) << endl;
	cout << sizeof(my_stu3) << endl;
	struct test t;
	cout << sizeof(t) << endl;
	int x4 = 1, y1 = -1;
	// 注意运算符的优先级
	int sign = ((x4 ^ y1) < 0) ? -1 : 1;
	cout << sign << endl;
	cout << is_opposite_sign(x4, y1) << endl;
	string s1 = "abc";
	s1.push_back('d');
	cout << s1 << endl;
	return 0;
}
