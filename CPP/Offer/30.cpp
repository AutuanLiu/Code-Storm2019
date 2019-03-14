class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {

        int cursum = array[0], maxsum = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            cursum += array[i];
            // 加上当前数时，比当前数还小，则从当前数开始累加
            if (cursum < array[i])
                cursum = array[i];
            if (cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};

// 迭代遍历
class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        int maxsum = array[0], cursum = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            if (cursum <= 0)
                cursum = array[i];
            else
                cursum += array[i];
            if (cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};

class Solution
{
  public:
    //动态规划
    //状态转移方程： sum[i]=max(sum[i-1]+a[i], a[i])
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        int maxsum = array[0], tempsum = array[0];
        //注意初始值 不能设为0 防止只有负数
        for (int i = 1; i < array.size(); i++)
        {
            tempsum = (tempsum < 0) ? array[i] : tempsum + array[i];
            maxsum = (tempsum > maxsum) ? tempsum : maxsum;
        }
        return maxsum;
    }
};
