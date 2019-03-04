class Solution
{
  public:
    vector<int> tmp;
    vector<vector<int>> buffer;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (root == NULL)
            return buffer;
        tmp.push_back(root->val);
        if (expectNumber - root->val == 0 && root->left == NULL && root->right == NULL)
        {
            buffer.push_back(tmp);
        }
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
        if (tmp.size() != 0)
            tmp.pop_back();
        return buffer;
    }
};

class Solution
{
  public:
    vector<vector<int>> buffer;
    vector<int> tmp;
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        if (root == NULL)
            return buffer;
        tmp.push_back(root->val);
        if ((expectNumber - root->val) == 0 && root->left == NULL && root->right == NULL)
        {
            buffer.push_back(tmp);
        }
        FindPath(root->left, expectNumber - root->val);
        FindPath(root->right, expectNumber - root->val);
        if (tmp.size() != 0)
            tmp.pop_back();
        return buffer;
    }
};

class Solution
{
  public:
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        int currentsum = 0;
        vector<int> temp;
        FindPath1(res, root, expectNumber, temp, currentsum);
        return res;
    }
    void FindPath1(vector<vector<int>> &res, TreeNode *root, int expectNumber, vector<int> &temp, int current)
    {
        current += root->val;
        temp.push_back(root->val);
        if (Isleaf(root) && expectNumber == current)
            res.push_back(temp);
        if (root->left != NULL)
        {
            FindPath1(res, root->left, expectNumber, temp, current);
            // temp.push_back(root->val);
        }
        if (root->right != NULL)
        {
            FindPath1(res, root->right, expectNumber, temp, current);
            //temp.push_back(root->val);
        }
        temp.pop_back();
    }
    bool Isleaf(TreeNode *Node)
    {
        if (Node->left == NULL && Node->right == NULL)
            return true;
        else
            return false;
    }
};
