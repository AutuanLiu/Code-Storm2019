/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (36.80%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 28.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 先序遍历之后，计算连续子数组的最大值
// 这种算法没有考虑到取得最大值的路径不存在的情况
// 这个思路不对
// class Solution {
// public:
//     // 先序遍历 获得路径
//     void preorder(TreeNode* root, vector<int>& path)
//     {
//         // 递归出口
//         if (root == nullptr)
//             return;
//         path.push_back(root->val);
//         preorder(root->left, path);
//         preorder(root->right, path);
//     }

//     int maxPathSum(TreeNode* root)
//     {
//         vector<int> path;
//         preorder(root, path);
//         // 连续子数组的最大和
//         int ret = path[0], tmp = path[0], n = path.size();
//         for (int i = 1; i < n; i++) {
//             tmp = tmp + path[i];
//             if (tmp < path[i])
//                 tmp = path[i];
//             ret = max(ret, tmp);
//         }
//         return ret;
//     }
// };

// 最大路径和可能出现在：
// 左子树中
// 右子树中
// 包含根节点与左右子树
// 自底向上的计算方法
// class Solution {
// public:
//     int max_path(TreeNode* root, int& ret)
//     {
//         // 递归出口
//         if (root == nullptr)
//             return 0;
//         // 计算左右子树的路径和
//         int left = max_path(root->left, ret);
//         int right = max_path(root->right, ret);

//         // 包含有两种不同的情况
//         // 包含根和左右子树
//         int rlr = root->val + max(0, left) + max(0, right);
//         // 包含根和左右子树的最大值
//         int tmp = root->val + max(0, max(left, right));

//         // 更新全局最大值  当前的最大值是两种情况中的最大值
//         ret = max(ret, max(rlr, ret));

//         // 全局最值 要么是根左、要么是根右，不会是根左右 因为不构成一个有效路径
//         return tmp;
//     }

//     int maxPathSum(TreeNode* root)
//     {
//         int ret = INT_MIN;
//         max_path(root, ret);
//         return ret;
//     }
// };
class Solution {
public:
    int max_path(TreeNode* root, int& ret)
    {
        // 递归出口
        if (root == nullptr)
            return 0;
        // 计算左右子树的路径和
        int left = max_path(root->left, ret);
        int right = max_path(root->right, ret);

        // 包含根和左右子树 开辟新的路径
        int rlr = root->val + max(0, left) + max(0, right);

        // 更新全局最大值  开辟新路径是否会更好
        ret = max(ret, rlr);

        // 从当前节点开始的最大路径和
        return root->val + max(0, max(left, right));
    }

    int maxPathSum(TreeNode* root)
    {
        int ret = INT_MIN;
        // 从当前节点开始的最大路径和
        max_path(root, ret);
        return ret;
    }
};
