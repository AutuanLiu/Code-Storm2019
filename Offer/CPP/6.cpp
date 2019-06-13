// 二分法解题
class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {
        if (rotateArray.size() <= 0)
            return -1;  // error
        int ptr1 = 0;
        int ptr2 = rotateArray.size() - 1;
        int mid = ptr1;  // 一旦第一个元素小于最后一个元素，说明数组本身是有序的，所以初始化为 ptr1
        while (rotateArray[ptr1] >= rotateArray[ptr2])
        {
            // 当 ptr1 和 ptr2 相邻的时候，结束
            if (ptr2 - ptr1 == 1)
            {
                mid = ptr2;
                break;
            }
            mid = (ptr1 + ptr2) / 2;
            // 当 ptr1, ptr2, mid 三者的数字相同时，只能使用顺序搜索
            if (rotateArray[mid] >= rotateArray[ptr1] && rotateArray[mid] <= rotateArray[ptr2])
                return inorderSearch(rotateArray);
            if (rotateArray[mid] >= rotateArray[ptr1])
                ptr1 = mid;
            else if (rotateArray[mid] <= rotateArray[ptr2])
                ptr2 = mid;
        }
        return rotateArray[mid];
    }

    int inorderSearch(vector<int> rotateArray)
    {
        int min_num = rotateArray[0];
        for(auto i = rotateArray.begin(); i != rotateArray.end(); i++)
        {
            if (*i < min_num)
                min_num = *i;
        }
        return min_num;
    }
};

// 顺序搜索，只需要找到分界点即可
class Solution
{
  public:
    int minNumberInRotateArray(vector<int> rotateArray)
    {

        if (rotateArray.size() <= 0)
            return -1;
        int bound = 0;  // 分界点的位置
        bool flag = false;
        // 只能取到倒数第二个元素
        for (; bound < rotateArray.size() - 1; bound++)
        {
            if (rotateArray[bound] > rotateArray[bound + 1])
            {
                flag = true;
                break;
            }
        }
            return flag?rotateArray[bound + 1]:rotateArray[0];
    }
};
