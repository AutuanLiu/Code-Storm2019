// 二叉树中和为某一值的路径.cpp
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

class Solution {
private:
    vector<int> path;
    vector<vector<int>> ret;

public:
    vector<vector<int>> FindPath(TreeNode* root, int target)
    {
        if (root == nullptr)
            return ret;
        // 先序遍历
        path.push_back(root->val);
        // 到达叶节点
        if (root->val == target && root->left == nullptr && root->right == nullptr) {
            ret.push_back(path);
        }
        FindPath(root->left, target - root->val);
        FindPath(root->right, target - root->val);
        // 回溯 删除当前的叶节点
        if (path.size() != 0)
            path.pop_back();
        return ret;
    }
};

class Solution {
public:
    vector<vector<int>> FindPath(TreeNode* root, int target)
    {
        // 使用 vector 来模拟栈，末尾为栈顶，首端为栈底
        if (root != nullptrptr || root->val > target) {
            // 先在 path 中存入根节点，首先访问的是根节点
            path.push_back(root->val);
            if (target - root->val == 0 && root->left == nullptrptr && root->right == nullptrptr)
                res.push_back(path);
            FindPath(root->left, target - root->val);
            FindPath(root->right, target - root->val);
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
