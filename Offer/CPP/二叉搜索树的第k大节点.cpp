// 二叉搜索树的第k大节点.cpp
// 二叉搜索树的中序遍历是有序的
class Solution {
public:
    TreeNode* KthNode(TreeNode* root, int k)
    {
        if (root == nullptr || k == 0)
            return nullptr;
        return kthNode(root, k);
    }

    TreeNode* kthNode(TreeNode* root, int& k)
    {
        TreeNode* target = nullptr;
        if (root->left != nullptr)
            target = kthNode(root->left, k);

        if (target == nullptr) {
            if (k == 1)
                target = root;
            k--;
        }

        if (target == nullptr && root->right != nullptr)
            target = kthNode(root->right, k);
        return target;
    }
};
