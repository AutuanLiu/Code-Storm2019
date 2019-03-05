class Solution
{
  public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == k)
                count++;
        }
        return count;
    }
};

class Solution
{
  public:
    int GetNumberOfK(vector<int> data, int k)
    {
        int start, end, mid, count = 0, i;
        unsigned int len = data.size();
        if (!len)
            return 0;
        start = 0;
        end = len - 1;
        mid = start;
        while (start < end)
        {
            mid = (start + end) >> 1;
            if (k > data[mid])
                start = mid + 1;
            if (k < data[mid])
                end = mid - 1;
            if (k == data[mid])
                break;
        }
        i = mid;
        while ((i >= 0) && (k == data[i]))
        {
            i--;
            count++;
        }
        i = mid + 1;
        while ((i < len) && (k == data[i]))
        {
            i++;
            count++;
        }
        return count;
    }
};

//暴力匹配，时间复杂度第O(n)
//观察数组本身的特性可以发现，排序数组这样做没有充分利用数组的特性，可以使用二分查找，找出数据，然后进行左右进行统计
//具体算法设计：     二分查找找到k的所在位置
//                 在原数组里面分别左右对k的出现次数进行统计
class Solution
{
  public:
    int BinarySearch(vector<int> data, int low, int high, int k)
    {
        while (low <= high)
        {
            int m = (high + low) / 2;
            if (data[m] == k)
                return m;
            else if (data[m] < k)
                low = m + 1;
            else
                high = m - 1;
        }
        return -1;
    }
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() == 0)
            return 0;
        int len = data.size();
        int KeyIndex = 0;

        KeyIndex = BinarySearch(data, 0, len - 1, k);
        if (KeyIndex == -1)
            return 0;
        int sumber = 1;
        int m = KeyIndex - 1;
        int n = KeyIndex + 1;

        while (m >= 0 && data[m] == k)
        {
            m--;
            sumber++;
        }
        while (n < len && data[n] == k)
        {
            n++;
            sumber++;
        }
        return sumber;
    }
};

class Solution
{
  public:
    int GetNumberOfK(vector<int> data, int k)
    {
        if (data.size() == 0)
            return 0;
        unordered_map<int, int> m;
        for (int i = 0; i < data.size(); i++)
            m[data[i]]++;
        return m[k];
    }
};

//因为data中都是整数，所以可以稍微变一下，不是搜索k的两个位置，而是搜索k-0.5和k+0.5
//这两个数应该插入的位置，然后相减即可。
class Solution
{
  public:
    int GetNumberOfK(vector<int> data, int k)
    {
        return biSearch(data, k + 0.5) - biSearch(data, k - 0.5);
    }

  private:
    int biSearch(const vector<int> &data, double num)
    {
        int s = 0, e = data.size() - 1;
        while (s <= e)
        {
            int mid = (e - s) / 2 + s;
            if (data[mid] < num)
                s = mid + 1;
            else if (data[mid] > num)
                e = mid - 1;
        }
        return s;
    }
};
