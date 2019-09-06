// 对称二叉树.cpp

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

// 所以 要先定义一个函数判断两个树是不是互为镜像
class Solution {
public:
    // 互为镜像的两棵树的特点 根节点的值相等，并且两棵树的左右子树相互对称
    bool isMirror(TreeNode* p, TreeNode* q)
    {
        // 都是空 则互为镜像
        if (p == nullptr && q == nullptr)
            return true;
        // 只有一个是空的 则不是镜像
        if (p == nullptr || q == nullptr)
            return false;
        // 其他情况下：根节点相等并且左右子树互为镜像
        return p->val == q->val && isMirror(p->left, q->right) && isMirror(p->right, q->left);
    }

    bool isSymmetrical(TreeNode* root)
    {
        return isMirror(root, root);
    }
};