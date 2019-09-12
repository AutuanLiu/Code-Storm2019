// 最小的k个数.cpp
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
    {
        int n = input.size();
        vector<int> vec;
        if (n < k)
            return vec;
        sort(input.begin(), input.end());
        for (int i = 0; i < k; i++)
            vec.push_back(input[i]);
        return vec;
    }
};

// 堆排序 小根堆
class Solution {
public:
    void min_heapifty(vector<int>& nums, int start, int end)
    {
        int parent = start;
        int child = 2 * parent + 1;
        while (child <= end) {
            // 先找出左右子树中最小的元素
            if (child + 1 <= end && nums[child + 1] < nums[child]) {
                child++;
            }
            if (nums[parent] <= nums[child]) {
                return;
            } else {
                swap(nums[parent], nums[child]);
                parent = child;
                child = 2 * parent + 1;
            }
        }
        return;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> ret;
        if (n < k)
            return ret;
        // 初始化
        for (int i = n / 2 - 1; i >= 0; i--) {
            min_heapifty(nums, i, n - 1);
        }
        for (int i = n - 1; i > n - k - 1; i--) {
            swap(nums[0], nums[i]);
            ret.push_back(nums[i]); // 最小的元素升序排列
            min_heapifty(nums, 0, i - 1); // 新的未排序的数组
        }
        return ret;
    }
};
