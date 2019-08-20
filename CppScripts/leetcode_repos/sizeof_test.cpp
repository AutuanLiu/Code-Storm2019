//https://www.jianshu.com/p/e4685bb2e2f3

#include <iostream>
#include "leetcode_repos.h"

#pragma pack(push, 1)  // ������ϵ��1ѹ��internal compiler stack��ͬʱ���õ�ǰ��packing alignmentΪ1
#pragma pack(push, 4)  // ��4Ҳѹ��ջ��ͬʱ���õ�ǰ��packing alignmentΪ4
#pragma pack(show)    // ��ʾ��ǰpacking alignment���ֽ���
#pragma pack(pop)     // ����internal compiler stack���˵�һ����¼�����ﵯ����4
#pragma pack(show)   // ��ʱ���˵�packing alignmentֵΪ1,

struct test
{
	char m1;
	short m2;
	int m3;
};

#pragma pack()  // ����Ϊȱʡֵ8 
#pragma pack(show)

struct test1
{
	char c;
	short s1;
	short s2;
	int i;
};

// ������뷽ʽ 4 λ
#pragma pack(4)
using namespace std;

struct B {
	float a;
	short b[3];
	char* cp[2];
};

#pragma pack(push, 1) // ������ ����Ϊ 1
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
	cout << sizeof(cp) << endl;  // 64 λϵͳ
	cout << sizeof(b) << endl;
	cout << sizeof(my_stu) << endl;
	cout << sizeof(my_stu1) << endl;
	cout << sizeof(my_stu3) << endl;
	struct test t;
	cout << sizeof(t) << endl;
	int x4 = 1, y1 = -1;
	// ע������������ȼ�
	int sign = ((x4 ^ y1) < 0) ? -1 : 1;
	cout << sign << endl;
	cout << is_opposite_sign(x4, y1) << endl;
	string s1 = "abc";
	s1.push_back('d');
	cout << s1 << endl;
	return 0;
}
