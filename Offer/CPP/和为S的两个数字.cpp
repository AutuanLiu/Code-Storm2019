// 和为S的两个数字.cpp
// 数组是递增排序的有序数组
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum)
    {
        int n = array.size();
        vector<int> ret;
        int left = 0, right = n - 1;
        while (left < right) {
            long long tmp = array[left] + array[right];
            if (tmp < sum) {
                left++;
            } else if (tmp > sum) {
                right--;
            } else {
                ret.push_back(array[left]);
                ret.push_back(array[right]);
                break;
            }
        }
        return ret;
    }
};