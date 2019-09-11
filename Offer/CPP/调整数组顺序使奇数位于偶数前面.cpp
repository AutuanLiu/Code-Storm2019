// 调整数组顺序使奇数位于偶数前面
// 双指针 冒泡排序
// 位运算一定要加足够多的括号  否则很容易就出错的

// 双指针或者partion就条件判断
class Solution {
public:
    void reOrderArray(vector<int>& array)
    {
        int n = array.size();
        if (n <= 1)
            return;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j > i; j--) {
                // if (array[j] % 2 == 1 && array[j - 1] % 2 == 0)
                if (((array[j] & 1) == 1) && ((array[j - 1] & 1) == 0))
                    swap(array[j], array[j - 1]);
            }
        }
        return;
    }
};

// 新创建一个数组，将奇数和偶数分别放进去
class Solution {
public:
    void reOrderArray(vector<int>& array)
    {
        vector<int> result;
        int num = array.size();
        for (int i = 0; i < num; i++) {
            if (array[i] % 2 == 1)
                result.push_back(array[i]);
        }
        for (int i = 0; i < num; i++) {
            if (array[i] % 2 == 0)
                result.push_back(array[i]);
        }
        array = result;
    }
};
