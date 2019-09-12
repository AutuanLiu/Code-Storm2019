#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int get_ret(vector<int>& nums)
{
    int ret = 0, n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1])
            ret += nums[i] - nums[i + 1];
    }
    return ret;
}

int main(void)
{
    string s, s1;
    getline(cin, s);
    stringstream in(s);
    vector<int> nums;
    while (getline(in, s1, ',')) {
        nums.push_back(stoi(s1));
    }
    cout << get_ret(nums) << endl;
    return 0;
}
