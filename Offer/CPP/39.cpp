class Solution
{
  public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (!pRoot)
            return true;
        int left_depth = Depth_longest(pRoot->left);
        int right_depth = Depth_longest(pRoot->right);
        if (abs(left_depth - right_depth) > 1)
            return false;
        else
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

  private:
    int Depth_longest(TreeNode *_root)
    {
        if (!_root)
            return 0;
        int left = Depth_longest(_root->left) + 1;
        int right = Depth_longest(_root->right) + 1;
        return left > right ? left : right;
    }
};

class Solution
{
  public:
    int TreeDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);

        return (left > right) ? (left + 1) : (right + 1);
    }

    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return true;

        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        int diff = left - right;
        if (diff > 1 || diff < -1)
            return false;

        return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }
};

class Solution
{
  public:
    bool IsBalanced_Solution(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return true;
        int leftDepth = getDepth(pRoot->left);
        int rightDepth = getDepth(pRoot->right);
        if (leftDepth > rightDepth + 1 || leftDepth + 1 < rightDepth)
            return false;
        else
            return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
    }

    int getDepth(TreeNode *pRoot)
    {
        if (pRoot == NULL)
            return 0;
        int leftDepth = getDepth(pRoot->left);
        int rightDepth = getDepth(pRoot->right);
        return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
    }
};
