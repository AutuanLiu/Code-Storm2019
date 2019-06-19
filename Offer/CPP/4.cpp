// https : //blog.csdn.net/CCSUXWZ/article/details/78237809

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 由前序和中序构建二叉树
class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty())
            return nullptr;
        vector<int> pre_left, pre_right, vin_left, vin_right;
        TreeNode *root = new TreeNode(pre[0]);  // 结构体的构造函数
        // 找到根节点在中序遍历的位置
        int root_pos;
        for (root_pos = 0; root_pos < vin.size(); root_pos++)
        {
            if (vin[root_pos] == pre[0])
                break;
        }

        // 找到 pre_left, pre_right, vin_left, vin_right
        for (int i = 0; i < vin.size(); i++)
        {
            if (i < root_pos)
            {
                vin_left.push_back(vin[i]); // [0:pos)
                pre_left.push_back(pre[i + 1]); // [1:(pos+1)]
            }
            else if (i > root_pos)
            {
                vin_right.push_back(vin[i]); // [(pos+1):]
                pre_right.push_back(pre[i]); // [(pos+1):]
            }
        }
        // 重建左右子树
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};

// 由后序和中序构建二叉树
class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> post, vector<int> vin)
    {
        if (post.empty() || vin.empty())
            return nullptr;
        vector<int> post_left, post_right, vin_left, vin_right;
        int root_val = post[post.size() - 1];
        TreeNode *root = new TreeNode(root_val); // 结构体的构造函数
        // 找到根节点在中序遍历的位置
        int root_pos;
        for (root_pos = 0; root_pos < vin.size(); root_pos++)
        {
            if (vin[root_pos] == root_val)
                break;
        }

        // 找到 post_left, post_right, vin_left, vin_right
        for (int i = 0; i < vin.size(); i++)
        {
            if (i < root_pos)
            {
                vin_left.push_back(vin[i]); // [0:pos)
                post_left.push_back(post[i]); // [0:pos]
            }
            else if (i > root_pos)
            {
                vin_right.push_back(vin[i + 1]); // [(pos+1):]
                post_right.push_back(post[i - 1]); // [(pos-1):-1]
            }
        }
        // 重建左右子树
        root->left = reConstructBinaryTree(post_left, vin_left);
        root->right = reConstructBinaryTree(post_right, vin_right);
        return root;
    }
};
