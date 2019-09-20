class Solution {
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index < 7)
            return index;
        vector<int> ret(index);
        ret[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i) {
            ret[i] = min(ret[t2] * 2, min(ret[t3] * 3, ret[t5] * 5));
            if (ret[i] == ret[t2] * 2)
                t2++;
            if (ret[i] == ret[t3] * 3)
                t3++;
            if (ret[i] == ret[t5] * 5)
                t5++;
        }
        return ret[index - 1];
    }
};

class Solution {
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;
        vector<int> ret(index);
        ret[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < index; ++i) {
            ret[i] = min(ret[t2] * 2, min(ret[t3] * 3, ret[t5] * 5));
            while (ret[i] >= ret[t2] * 2)
                ++t2;
            while (ret[i] >= ret[t3] * 3)
                ++t3;
            while (ret[i] >= ret[t5] * 5)
                ++t5;
        }

        return ret[index - 1];
    }
};
