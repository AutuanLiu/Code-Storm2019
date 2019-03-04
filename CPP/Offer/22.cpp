class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> r;
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            if (!root)
                continue;
            r.push_back(root->val);
            q.push(root->left);
            q.push(root->right);
        }
        return r;
    }
};

#include <queue>
class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        queue<TreeNode *> q;
        vector<int> v;
        if (root == NULL)
            return v;
        q.push(root);
        while (!q.empty())
        {
            root = q.front();
            q.pop();
            v.push_back(root->val);
            if (root->left)
                q.push(root->left);
            if (root->right)
                q.push(root->right);
        }
        return v;
    }
};

class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {

        vector<int> que;
        queue<TreeNode *> q;
        TreeNode *fr;
        if (root == NULL)
            return que;
        q.push(root);
        while (!q.empty())
        {
            fr = q.front();
            que.push_back(fr->val);
            if (fr->left != NULL)
                q.push(fr->left);
            if (fr->right != NULL)
                q.push(fr->right);
            q.pop();
        }

        return que;
    }
};
