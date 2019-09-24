// 0 ~~ n - 1中缺失的数字.cpp
// 在排序数组中找出第一个值和下标不相等的元素
// 二分查找的变种 如果中间的元素和下标相等那么查找右边
int getMissingNumber(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return -1;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) >> 1;
        if (nums[mid] != middle) {
            if (mid == 0 || nums[mid - 1] == mid - 1)
                return mid;
            right = mid - 1;
        } else {
            // 中间元素和下标相等 则只需要查找右边即可
            left = mid + 1;
        }
        // 都在
        if (left == right)
            return n;
    }
    return -1;
}
