// 二叉树的镜像.cpp
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

// 队列
class Solution {
public:
    void Mirror(TreeNode* root)
    {
        if (root == nullptr)
            return;
        queue<TreeNode*> qu;
        TreeNode* p = nullptr;
        qu.push(root);
        while (qu.size() > 0) {
            p = qu.front();
            qu.pop();
            swap(p->left, p->right);
            if (p->left)
                qu.push(p->left);
            if (p->right)
                qu.push(p->right);
        }
    }
};

// 递归
class Solution {
public:
    void Mirror(TreeNode* root)
    {
        if (!root)
            return;

        // 交换左右子树
        TreeNode* p;
        p = root->left;
        root->left = root->right;
        root->right = p;
        Mirror(root->left);
        Mirror(root->right);
    }
};


