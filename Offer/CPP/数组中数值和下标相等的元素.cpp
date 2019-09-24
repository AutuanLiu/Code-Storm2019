// 数组中数值和下标相等的元素.cpp
int getNum(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return -1;
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == mid)
            return mid;
        if (nums[mid] > mid)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
