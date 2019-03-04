class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return;
        queue<TreeNode *> qu;
        TreeNode *p = NULL;
        qu.push(pRoot);
        while (qu.size())
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

class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return;
        swap(pRoot->left, pRoot->right);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        return;
    }
};

class Solution
{
  public:
    void Mirror(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return;

        TreeNode *pTmp;
        pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
        /**if (pRoot->left) {
            Mirror(pRoot->left);

            TreeNode *pTmp;
            pTmp = pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = pTmp;
        }
        if (pRoot->right) {
            Mirror(pRoot->right);

            TreeNode *pTmp;
            pTmp = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = pTmp;
        }**/
    }
};
