class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> seq)
    {
        int len = seq.size();
        int *arr = new int[len];

        if (!len)
            return false;
        for (int i = 0; i < len; i++)
            arr[i] = seq[i];

        return myVerifySquenceOfBST(arr, len);
    }

    bool myVerifySquenceOfBST(int *arr, int len)
    {
        int root = arr[len - 1];
        int i, j;

        for (i = 0; i < len - 1; i++)
            if (arr[i] > root)
                break;
        for (j = i; j < len - 1; j++)
            if (arr[j] < root)
                return false;

        bool left = true, right = true;
        if (i > 0)
            left = myVerifySquenceOfBST(arr, i);
        if (j < len - 1)
            right = myVerifySquenceOfBST(arr + i, len - i - 1);

        return left && right;
    }
};

class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int length = sequence.size();
        if (length == 0)
            return false;
        int i = 0;
        while (--length)
        {
            while (sequence[i++] < sequence[length])
                ;
            while (sequence[i++] > sequence[length])
                ;
            if (i < length)
                return false;
            i = 0;
        }
        return true;
    }
};

class Solution
{
  public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        return bst(sequence, 0, sequence.size() - 1);
    }
    bool bst(vector<int> sequence, int begin, int end)
    {
        if (sequence.empty() || begin > end)
            return false;
        int root = sequence[end];
        int i = begin;
        for (; i < end; ++i)
            if (sequence[i] > root) //i坐标为右子树第一个节点
                break;
        for (int j = i; j < end; ++j)
            if (sequence[j] < root)
                return false;
        bool left = true;
        if (i > begin)
            left = bst(sequence, begin, i - 1);
        bool right = true;
        if (i < end - 1)
            right = bst(sequence, i, end - 1);
        return left && right;
    }
};
