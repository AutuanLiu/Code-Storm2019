class Solution {
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index < 7)
            return index;
        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0, i;
        for (i = 1; i < index; ++i) {
            res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
            if (res[i] == res[t2] * 2)
                t2++;
            if (res[i] == res[t3] * 3)
                t3++;
            if (res[i] == res[t5] * 5)
                t5++;
        }
        return res[index - 1];
    }
};

class Solution {
public:
    int GetUglyNumber_Solution(int index)
    {
        if (index <= 0)
            return 0;
        vector<int> numbers(index);
        numbers[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < index; ++i) {
            numbers[i] = min(numbers[t2] * 2, min(numbers[t3] * 3, numbers[t5] * 5));
            while (numbers[i] >= numbers[t2] * 2)
                ++t2;
            while (numbers[i] >= numbers[t3] * 3)
                ++t3;
            while (numbers[i] >= numbers[t5] * 5)
                ++t5;
        }

        return numbers[index - 1];
    }
};
