class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        return max(TreeDepth(pRoot->left), TreeDepth(pRoot->right)) + 1;
    }
};

class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;

        int nleft = TreeDepth(pRoot->left);
        int nright = TreeDepth(pRoot->right);

        if (nleft > nright)
            return nleft + 1;
        else
            return nright + 1;
    }
};

class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (!pRoot)
            return 0;
        return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
    }
};
