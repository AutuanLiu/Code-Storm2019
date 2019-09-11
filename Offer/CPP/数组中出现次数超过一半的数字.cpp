// 一次遍历
// 数组中出现次数超过一半的数字.cpp
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int cnt = 1; // cnt 的初始值
        int ret = nums[0]; // 用于保存结果
        for (int i = 1; i < n; i++) {
            if (cnt == 0) {
                ret = nums[i];
                cnt = 1;
            } else if (nums[i] == ret)
                cnt++;
            else
                cnt--;
        }

        // 用于判断结果是否满足要求
        int times = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == ret)
                times++;
        }

        if (times <= n / 2)
            return 0;
        else
            return ret;
    }
};

// 二分加快排
class Solution {
public:
    int partition(vector<int>& nums, int start, int end)
    {
        int lb = start, rb = end;
        int pivot = nums[lb];
        while (lb < rb) {
            for (; lb < rb && nums[rb] >= pivot; rb--) {
            }
            if (lb < rb)
                nums[lb++] = nums[rb];
            for (; lb < rb && nums[lb] <= pivot; lb++) {
            }
            if (lb < rb)
                nums[rb--] = nums[lb];
        }
        nums[lb] = pivot;
        return lb; // 分割点 元素位置已经固定
    }

    int MoreThanHalfNum_Solution(vector<int> nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        // 二分
        int mid = n >> 1, start = 0, end = n - 1;
        int pivot = partition(nums, start, end);
        while (pivot != mid) {
            if (pivot > mid) {
                end = pivot - 1;
                pivot = partition(nums, start, end);
            } else {
                start = pivot + 1;
                pivot = partition(nums, start, end);
            }
        }
        int ret = nums[mid];
        return ret;
    }
};