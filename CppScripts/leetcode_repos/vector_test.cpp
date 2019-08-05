#include "leetcode_repos.h"

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
	// 按照从大到小的顺序进行排序
	sort(nums.begin(), nums.end(), greater<int>());
	print_vector(nums);
	// 默认的是就是用 0 初始化
	vector<int> ret(5);
	print_vector(ret);

	// 查找数组元素
	auto x = find(nums.begin(), nums.end(), -3);
	cout << distance(nums.begin(), x) << endl;

	string s = "abcdeabc";
	cout << s.find("dea") << endl;
	vector<string> s1 = {"acd", "def", "ert"};
	print_vector(s1);
	return 0;
}
