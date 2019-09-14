// 数据流中的中位数.cpp
class Solution {
private:
    vector<int> min;
    vector<int> max;

public:
    void Insert(int num)
    {
        int size = min.size() + max.size();
        if ((size & 1) == 0) {
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<int>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<int>());
                max.pop_back();
            }
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<int>());
        } else {
            if (min.size() > 0 && num > min[0]) {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<int>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<int>());
        }
    }

    double GetMedian()
    {
        int size = min.size() + max.size();
        if (size <= 0)
            return 0;
        if ((size & 1) == 0)
            return (max[0] + min[0]) / 2.0;
        else
            return min[0];
    }
};