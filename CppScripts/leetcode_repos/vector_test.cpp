#include "leetcode_repos.h"

const long long xx = -(1 << 63);
const long long y = (1 << 63) - 1;

int main(int argc, char** argv)
{
	vector<int> nums = { 1, 2, -3, 4, 5 };
	print_vector(nums);
	reverse(nums.begin(), nums.end());
	print_vector(nums);
	vector<int>::iterator it = max_element(nums.begin(), nums.end());
	cout << *it << endl;
	cout << nums.at(0) << endl;
	cout << distance(nums.begin(), it) << endl;
	// ���մӴ�С��˳���������
	sort(nums.begin(), nums.end(), greater<int>());
	print_vector(nums);
	// Ĭ�ϵ��Ǿ����� 0 ��ʼ��
	vector<int> ret(5);
	print_vector(ret);

	// ��������Ԫ��
	auto x = find(nums.begin(), nums.end(), -3);
	cout << distance(nums.begin(), x) << endl;

	string s = "abcdeabc";
	cout << s.find("dea") << endl;
	vector<string> s1 = {"acd", "def", "ert"};
	print_vector(s1);
	
	cout << xx << " " << INT64_MIN << endl;
	cout << y << " " << INT64_MAX << endl;
	return 0;
}
