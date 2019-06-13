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
    vector<vector<int>> FindPath(TreeNode *root, int expectNumber)
    {
        // 使用 vector 来模拟栈，末尾为栈顶，首端为栈底
        if (root != nullptr || root->val > expectNumber)
        {
            // 先在 path 中存入根节点，首先访问的是根节点
            path.push_back(root->val);
            if (expectNumber - root->val == 0 && root->left == nullptr && root->right == nullptr)
                res.push_back(path);
            FindPath(root->left, expectNumber - root->val);
            FindPath(root->right, expectNumber - root->val);
            if (path.size() > 0)
                path.pop_back();
        }
        return res;
    }

  private:
    // 类的全局变量
    // 递归调用时，全局使用的变量应当放到外面
    vector<int> path;
    vector<vector<int>> res;
};
