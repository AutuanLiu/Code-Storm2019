struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};


class Solution
{
  public:
    vector<int> PrintFromTopToBottom(TreeNode *root)
    {
        queue<TreeNode*> q;
        vector<int> v;
        if (root != nullptr)
        {
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
        }
        return v;
    }
};
