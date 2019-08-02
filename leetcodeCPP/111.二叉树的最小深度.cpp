/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (39.47%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 61.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
// class Solution {
// public:
//     int minDepth(TreeNode* root)
//     {
//         if (root == nullptr)
//             return 0;
//         // 处理只有左子树或者右子树的情况
//         if (root->left == nullptr)
//             return minDepth(root->right) + 1;
//         if (root->right == nullptr)
//             return minDepth(root->left) + 1;
//         int leftDepth = minDepth(root->left);
//         int rightDepth = minDepth(root->right);
//         return 1 + min(leftDepth, rightDepth);
//     }
// };

// 上述算法的化简版本
class Solution {
public:
    int minDepth(TreeNode* root)
    {
        // 为nullptr 返回的是 0
        if (root == nullptr)
            return 0;
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        // 处理只有左子树或者右子树的情况或者叶子节点
        if (root->left == nullptr || root->right == nullptr)
            return leftDepth + rightDepth + 1;

        // 同时存在左右子树
        return 1 + min(leftDepth, rightDepth);
    }
};
