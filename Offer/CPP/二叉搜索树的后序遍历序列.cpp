// 二叉搜索树的后序遍历序列.cpp
// 任意两个数字互不相同
// 二叉搜索树 左边的数字比根小右边的数字比根大
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int n = sequence.size();
        return bst(sequence, 0, n - 1);
    }

    bool bst(vector<int>& sequence, int begin, int end)
    {
        if (sequence.empty() || begin > end)
            return false;
        int root = sequence[end]; // 树的根节点 数字最大
        // 后序遍历为 左右根 按照数字大小可以找到左右子树的分界点
        // 已经保证左子树都小于根节点的数值
        int pivot = begin;
        for (; pivot < end; ++pivot)
            if (sequence[pivot] > root)
                break;

        // 右子树的遍历 不包括根节点
        // 如果在右子树中存在小于根节点的数字 则返回false
        for (int j = pivot; j < end; ++j)
            if (sequence[j] < root)
                return false;

        // 左右子树同时满足条件
        // 初始化为 true 是因为当不存在左子树也不存在右子树的时候 根节点是一个二叉搜索树
        bool left = true, right = true;
        if (pivot > begin)
            left = bst(sequence, begin, pivot - 1);
        if (pivot < end - 1)
            right = bst(sequence, pivot, end - 1);
        return left && right;
    }
};

// 二叉搜索树的左右子树也都是二叉搜索树
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence)
    {
        int n = sequence.size();
        if (n == 0)
            return false;
        int pivot = 0;
        // 构造左右子树的序列
        vector<int> left_seq, right_seq;
        // 寻找左右子树的分割点
        int root = sequence.back(); // sequence[n-1]
        for (; pivot < n - 1; pivot++) {
            if (sequence[pivot] > root)
                break;
            left_seq.push_back(sequence[pivot]); // 左子树
        }

        // 右子树判断，如果右子树中存在小于root的数值，则返回false
        for (int j = pivot; j < n - 1; j++) {
            if (sequence[j] < root)
                return false;
            right_seq.push_back(sequence[j]);
        }

        // 递归遍历左子树, 当不存在左子树时，左子树是后序遍历序列
        bool left = true, right = true;
        if (pivot > 0)
            // 存在左子树序列
            left = VerifySquenceOfBST(left_seq);
        if (pivot < n - 1)
            // 存在右子树序列
            right = VerifySquenceOfBST(right_seq);
        return left && right;
    }
};
