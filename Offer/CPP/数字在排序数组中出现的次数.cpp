// 数字在排序数组中出现的次数.cpp
// class Solution {
// public:
//     int GetNumberOfK(vector<int> data, int k)
//     {
//         auto resultPair = equal_range(data.begin(), data.end(), k);
//         return resultPair.second - resultPair.first;
//     }
// };

//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
// class Solution {
// public:
//     int GetNumberOfK(vector<int> data, int k)
//     {
//         return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
//     }

// private:
//     int biSearch(const vector<int>& data, double num)
//     {
//         int s = 0, e = data.size() - 1;
//         while (s <= e) {
//             int mid = (e - s) / 2 + s;
//             if (data[mid] < num)
//                 s = mid + 1;
//             else if (data[mid] > num)
//                 e = mid - 1;
//         }
//         return s;
//     }
// };

class Solution {
public:
    int GetNumberOfK(vector<int> array, int k)
    {
        int n = array.size();
        if (n == 0) {
            return 0;
        }
        int firstK = getFirstK(array, k, 0, n - 1);
        int lastK = getLastK(array, k, 0, n - 1);
        if (firstK != -1 && lastK != -1) {
            return lastK - firstK + 1;
        }
        return 0;
    }

private:
    //递归写法
    int getFirstK(vector<int> array, int k, int start, int end)
    {
        if (start > end)
            return -1;

        int mid = (start + end) >> 1;
        if (array[mid] > k)
            return getFirstK(array, k, start, mid - 1);
        else if (array[mid] < k)
            return getFirstK(array, k, mid + 1, end);
        else if (mid - 1 >= 0 && array[mid - 1] == k)
            return getFirstK(array, k, start, mid - 1);
        else
            return mid;
    }

    //循环写法
    int getLastK(vector<int> array, int k, int start, int end)
    {
        int n = array.size();
        int mid = (start + end) >> 1;
        while (start <= end) {
            if (array[mid] > k)
                end = mid - 1;
            else if (array[mid] < k)
                start = mid + 1;
            else if (mid + 1 < n && array[mid + 1] == k)
                start = mid + 1;
            else
                return mid;

            mid = (start + end) >> 1;
        }
        return -1;
    }
};
