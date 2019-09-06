// 二叉搜索树的后序遍历序列.cpp
class Solution {
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

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        if (sequence.size() == 0)
            return false;
        int pivot = 0;
        // 构造左右子树的序列
        vector<int> left_seq, right_seq;
        // 寻找左右子树的分割点
        int root = sequence.back();
        for (; pivot < sequence.size() - 1; pivot++) {
            if (sequence[pivot] > root)
                break;
            left_seq.push_back(sequence[pivot]);
        }
        // 右子树判断，如果右子树中存在小于root的数值，则返回false
        for (int j = pivot; j < sequence.size() - 1; j++) {
            if (sequence[j] < root)
                return false;
            right_seq.push_back(sequence[j]);
        }

        // 递归遍历左子树, 当不存在左子树时，左子树是后序遍历序列
        bool left = true, right = true;
        if (pivot > 0)
            // 存在左子树序列
            left = VerifySquenceOfBST(left_seq);
        if (pivot < sequence.size() - 1)
            // 存在右子树序列
            right = VerifySquenceOfBST(right_seq);
        return left && right;
    }
};
