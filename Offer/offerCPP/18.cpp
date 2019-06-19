struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL)
    {
    }
};

// 队列
class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == nullptr)
            return;
        queue<TreeNode *> qu;
        TreeNode *p = nullptr;
        qu.push(pRoot);
        while (qu.size() > 0)
        {
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
class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (!pRoot)
            return;

        // 交换左右子树
        TreeNode *pTmp;
        pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
