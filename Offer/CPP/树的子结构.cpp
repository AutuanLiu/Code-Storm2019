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
    // 查找与根节点一样的节点
    bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
    {
        if (pRootA == nullptr || pRootB == nullptr)
            return false;
        // 左子树右子树根是否有B子树
        return isSubtree(pRootA, pRootB) || HasSubtree(pRootA->left, pRootB) || HasSubtree(pRootA->right, pRootB);
    }

    // 判断以R为根节点的子树是不是和B有相同的结构
    bool isSubtree(TreeNode* pRootA, TreeNode* pRootB)
    {
        if (pRootB == nullptr)
            return true;
        if (pRootA == nullptr)
            return false;
        if (pRootB->val == pRootA->val)
            // 判断左右子树是否相同
            return isSubtree(pRootA->left, pRootB->left) && isSubtree(pRootA->right, pRootB->right);
        return false;
    }
};
