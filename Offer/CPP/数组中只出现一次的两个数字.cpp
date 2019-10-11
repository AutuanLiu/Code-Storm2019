// 数组中只出现一次的两个数字.cpp
class Solution {
public:
    // 找到数字右边第一个位 1
    unsigned int findFirstBitIs1(int num)
    {
        int idx = 0;
        while ((num & 1) == 0 && (idx < 8 * sizeof(int))) {
            num = num >> 1;
            ++idx;
        }
        return idx;
    }

    void FindNumsAppearOnce(vector<int> data, int* num1, int* num2)
    {
        int n = data.size();
        if (n < 2)
            return;
    }
};
