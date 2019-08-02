/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (61.54%)
 * Likes:    121
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 33.6K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
 * 
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

// 按照正常的程序遍历 然后反转
// class Solution {
// public:
//     void levelOrder(TreeNode* root, int level, vector<vector<int>>& ret)
//     {
//         if (root == nullptr)
//             return;

//         // ret.size() == level, 如果ret.size() <= level 则应该添加一层
//         if (ret.size() <= level)
//             ret.push_back(vector<int>{});
//         ret[level].push_back(root->val);
//         levelOrder(root->left, level + 1, ret);
//         levelOrder(root->right, level + 1, ret);
//     }

//     vector<vector<int>> levelOrderBottom(TreeNode* root)
//     {
//         vector<vector<int>> ret;
//         levelOrder(root, 0, ret);
//         // 正常的层序遍历 然后反转一下
//         reverse(ret.begin(), ret.end());
//         return ret;
//     }
// };

// 按照题目要求进行反向填充
// 但是必须事先分配内存才能赋值，多以需要知道二叉树的深度
class Solution {
public:
    int depth(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        return max(depth(root->left), depth(root->right)) + 1;
    }

    void levelOrder(TreeNode* root, int level, vector<vector<int>>& ret)
    {
        if (root == nullptr || level < 0)
            return;

        ret[level].push_back(root->val);
        levelOrder(root->left, level - 1, ret);
        levelOrder(root->right, level - 1, ret);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        int d = depth(root);
        vector<vector<int>> ret(d, vector<int>{});
        levelOrder(root, d - 1, ret);
        return ret;
    }
};
