// 树的子结构.cpp
struct TreeNode {
    int val; // 注意这个类型 int(==)/double(Equal<abs(a-b)<1e-5>)
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

// 递归思路
class Solution {
public:
    bool HasSubtree(TreeNode* A, TreeNode* B)
    {
        if (A == nullptr || B == nullptr)
            return false;
        // 左子树右子树根是否有B子树
        return isSubtree(A, B) || HasSubtree(A->left, B) || HasSubtree(A->right, B);
    }

    // 判断以R为根节点的子树是不是和B有相同的结构
    bool isSubtree(TreeNode* A, TreeNode* B)
    {
        if (B == nullptr) // 空树是任何树的子树
            return true;
        if (A == nullptr) // 空树没有任何形式的子树
            return false;
        // 根节点相同判断是否左右子树也相同
        if (B->val == A->val)
            return isSubtree(A->left, B->left) && isSubtree(A->right, B->right);
        return false; // 其他情况 都是 false
    }
};
