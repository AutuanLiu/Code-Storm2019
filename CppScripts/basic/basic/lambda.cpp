// C++的lambda表达式

// [ 捕获 ] <模板形参>(可选)(C++20) ( 形参 ) 说明符(可选) 异常说明 attr -> ret requires(可选)(C++20) { 函数体 }	(1)	
// [ 捕获 ] ( 形参 ) -> ret { 函数体 }	(2)	
// [ 捕获 ] ( 形参 ) { 函数体 }	(3)	
// [ 捕获 ] { 函数体 }
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> nums = { 3, 4, 1, -3, 4, 5, 8, -434, 0, 12 };
    // 从大到小进行排列
    // sort(nums.begin(), nums.end(), [](int a, int b) -> bool { return a > b; });
    // sort(nums.begin(), nums.end(), [=](int a, int b) -> bool { return a > b; });
    sort(nums.begin(), nums.end(), [&](int a, int b) -> bool { return a > b; });
    // sort(nums.begin(), nums.end(), greater<int>());
    for (int& it : nums) {
        cout << it << " ";
    }
    return 0;
}