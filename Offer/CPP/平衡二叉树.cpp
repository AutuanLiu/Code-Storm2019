// 平衡二叉树.cpp
// 平衡二叉树的左右子树都是平衡二叉树，反之亦然
class Solution {
public:
    int get_depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int nleft = get_depth(root->left);
        int nright = get_depth(root->right);

        return nleft > nright ? nleft + 1 : nright + 1;
    }

    bool IsBalanced_Solution(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        int nleft = get_depth(root->left);
        int nright = get_depth(root->right);

        if (abs(nleft - nright) > 1)
            return false;
        return IsBalanced_Solution(root->left) && IsBalanced_Solution(root->right);
    }
};
