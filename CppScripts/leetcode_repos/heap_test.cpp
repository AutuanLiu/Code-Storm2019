#include "leetcode_repos.h"

int main(int argc, char** argv)
{
	vector<int> v{ 3, 1, 4, 1, 5, 9 };

	make_heap(v.begin(), v.end());

	cout << "v: ";
	for (auto i : v) cout << i << ' ';
	cout << '\n';

	pop_heap(v.begin(), v.end()); // �ƶ����Ԫ�ص���β

	cout << "after pop_heap: ";
	for (auto i : v) cout << i << ' ';
	cout << '\n';

	int largest = v.back();
	v.pop_back();  // ʵ���Ƴ����Ԫ��
	cout << "largest element: " << largest << '\n';

	cout << "heap without largest: ";
	for (auto i : v) cout << i << ' ';
	cout << '\n';
}