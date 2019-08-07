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
class Solution {
public:
    // 先序遍历 获得路径
    void preorder(TreeNode* root, vector<int>& path)
    {
        // 递归出口
        if (root == nullptr)
            return;
        path.push_back(root->val);
        preorder(root->left, path);
        preorder(root->right, path);
    }

    int maxPathSum(TreeNode* root)
    {
        vector<int> path;
        preorder(root, path);
        // 连续子数组的最大和
        int ret = path[0], tmp = path[0], n = path.size();
        for (int i = 1; i < n; i++) {
            tmp = tmp + path[i];
            if (tmp < path[i])
                tmp = path[i];
            ret = max(ret, tmp);
        }
        return ret;
    }
};
