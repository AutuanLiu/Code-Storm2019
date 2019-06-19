static const auto io_sync_off = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
  public:
    static constexpr int P = 1000000007;
    vector<int>::iterator it;
    int InversePairs(vector<int> &data)
    {
        it = data.begin();
        if (data.empty())
            return 0;
        vector<int> dup(data);
        return merge_sort(data.begin(), data.end(), dup.begin());
    }
    //template<class RanIt>
    using RanIt = vector<int>::iterator;
    int merge_sort(const RanIt &begin1, const RanIt &end1, const RanIt &begin2)
    {
        int len = end1 - begin1;
        if (len < 2)
            return 0;
        int mid = (len + 1) >> 1;
        auto m1 = begin1 + mid, m2 = begin2 + mid;
        auto i = m1, j = end1, k = begin2 + len;
        int ans = (merge_sort(begin2, m2, begin1) + merge_sort(m2, k, m1)) % P;
        for (--i, --j, --k; i >= begin1 && j >= m1; --k)
        {
            if (*i > *j)
            {
                *k = *i, --i;
                (ans += j - m1 + 1) %= P;
            }
            else
                *k = *j, --j;
        }
        if (i >= begin1)
            copy(begin1, i + 1, begin2);
        else
            copy(m1, j + 1, begin2);
        return ans;
    }
};

static const auto io_sync_off = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();
class Solution
{
  public:
    int InversePairs(vector<int> data)
    {
        if (data.size() < 2)
            return 0;
        vector<int> copy;
        for (int i = 0; i < data.size(); i++)
        {
            copy.push_back(data[i]);
        }
        long long count = InversePairsCore(data, copy, 0, data.size() - 1);
        copy.clear();
        return count % 1000000007;
    }

    long long InversePairsCore(vector<int> &data, vector<int> &copy, int begin, int end)
    {
        if (begin == end)
        {
            copy[begin] = data[begin];
            return 0;
        }

        int L = (end - begin) / 2;
        long long left = InversePairsCore(copy, data, begin, begin + L);
        long long right = InversePairsCore(copy, data, begin + L + 1, end);
        int i = begin + L;
        int j = end, inxcopy = end;
        long long count = 0;
        while (i >= begin && j >= begin + L + 1)
        {
            if (data[i] > data[j])
            {
                copy[inxcopy--] = data[i--];
                count += j - begin - L;
            }
            else
                copy[inxcopy--] = data[j--];
        }
        //for(i=begin;i<=end;i++) copy[i]=data[i];
        for (; i >= begin; i--)
            copy[inxcopy--] = data[i];
        for (; j >= begin + L + 1; j--)
            copy[inxcopy--] = data[j];
        return left + right + count;
    }
};

static const auto io_sync_off = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
  public:
    //constexpr 作用是指定变量或函数的值能出现在常量表达式中
    static constexpr int P = 1000000007;
    vector<int>::iterator it;

    int InversePairs(vector<int> data)
    {
        it = data.begin();

        if (data.empty())
            return 0;

        vector<int> dup(data);

        return merge_sort(data.begin(), data.end(), dup.begin());
    }

    using RanIt = vector<int>::iterator;
    int merge_sort(const RanIt &begin1, const RanIt &end1, const RanIt &begin2)
    {
        int len = end1 - begin1;

        if (len < 2)
            return 0;

        int mid = (len + 1) >> 1;
        auto m1 = begin1 + mid;
        auto m2 = begin2 + mid;
        auto i = m1;
        auto j = end1;
        auto k = begin2 + len;

        int ans = (merge_sort(begin2, m2, begin1) + merge_sort(m2, k, m1)) % P;
        for (--i, --j, --k; i >= begin1 && j >= m1; --k)
        {
            if (*i > *j)
            {
                *k = *i;
                --i;
                (ans += j - m1 + 1) %= P;
            }
            else
            {
                *k = *j;
                --j;
            }
        }

        if (i >= begin1)
        {
            copy(begin1, i + 1, begin2);
        }
        else
        {
            copy(m1, j + 1, begin2);
        }

        return ans;
    }
};
