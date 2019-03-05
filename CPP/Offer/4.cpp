// https : //blog.csdn.net/CCSUXWZ/article/details/78237809

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
  public:
    TreeNode * R(vector<int> a, int abegin, int aend, vector<int> b, int bbegin, int bend)
    {
        if (abegin >= aend || bbegin >= bend)
            return NULL;
        TreeNode *root = new TreeNode(a[abegin]);
        //root->val=a[abegin];
        int pivot;
        for (pivot = bbegin; pivot < bend; pivot++)
            if (b[pivot] == a[abegin])
                break;
        root->left = R(a, abegin + 1, abegin + pivot - bbegin + 1, b, bbegin, pivot);
        root->right = R(a, abegin + pivot - bbegin + 1, aend, b, pivot + 1, bend);
        return root;
    }

    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        return R(pre, 0, pre.size(), vin, 0, vin.size());
    }
};

class Solution
{
  public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin)
    {
        if (pre.empty() || vin.empty())
            return NULL;
        int count = 0;
        for (int i = 0; i < vin.size(); ++i)
        {
            if (pre[0] == vin[i])
                count++;
        }
        if (count != 1)
            return NULL;

        vector<int> pre_left, pre_right, vin_left, vin_right;
        int val = pre[0];
        TreeNode *root = new TreeNode(val);
        int pos;

        for (pos = 0; pos < vin.size(); ++pos)
        {
            if (vin[pos] == val)
                break;
        }

        for (int i = 0; i < vin.size(); ++i)
        {

            if (i < pos)
            {
                vin_left.push_back(vin[i]);
                pre_left.push_back(pre[i + 1]);
            }
            else if (i > pos)
            {
                vin_right.push_back(vin[i]);
                pre_right.push_back(pre[i]);
            }
        }
        root->left = reConstructBinaryTree(pre_left, vin_left);
        root->right = reConstructBinaryTree(pre_right, vin_right);
        return root;
    }
};
