class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {

        int cursum = array[0];
        int maxsum = array[0];
        for (int i = 1; i < array.size(); i++)
        {
            cursum += array[i];
            if (cursum < array[i])
                cursum = array[i];
            if (cursum > maxsum)
                maxsum = cursum;
        }
        return maxsum;
    }
};

class Solution
{
  public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int maxx = INT_MIN;
        int cursum = 0;
        for (int i = 0; i < array.size(); i++)
        {
            if (cursum < 0)
            {
                cursum = array[i];
            }
            else
                cursum += array[i];
            maxx = max(maxx, cursum);
        }
        return maxx;
    }
};

class Solution
{
  public:
    //动态规划
    //状态转移方程： sum[i]=max(sum[i-1]+a[i],a[i])
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if (array.empty())
            return 0;
        int maxsum = array[0], tempsum = array[0]; //注意初始值 不能设为0 防止只有负数
        for (int i = 1; i < array.size(); i++)     //从1开始 因为0的情况在初始化时完成了
        {
            //tempsum = (tempsum < 0) ? array[i] : tempsum + array[i];
            if (tempsum < 0)
            {
                tempsum = array[i];
            }
            else
            {
                tempsum = tempsum + array[i];
            }
            //sum = (tempsum > sum) ? tempsum : sum;
            if (tempsum > maxsum)
            {
                maxsum = tempsum;
            }
            else
            {
                maxsum = maxsum;
            }
        }
        return maxsum;
    }
};
