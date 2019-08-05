#include <iostream>
#pragma pack(4)
using namespace std;

struct B {
	float a;
	short b[3];
	char* cp[2];
};

#pragma pack(push, 1)
struct stu {
	char sex;
	int length;
	char name[10];
};

#pragma pack()
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

struct stu my_stu;
struct stu1 my_stu1;
struct stu3 my_stu3;

int main()
{
	B b;
	cout << sizeof(b) << endl;
	//cout << sqrt(130.0) << endl;
	cout << sizeof(my_stu) << endl;
	cout << sizeof(my_stu1) << endl;
	cout << sizeof(my_stu3) << endl;
	return 0;
}