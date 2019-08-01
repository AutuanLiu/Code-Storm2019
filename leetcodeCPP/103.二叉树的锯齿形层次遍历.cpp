/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (49.83%)
 * Likes:    85
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 28.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
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
class Solution {

public:
    void zigzag(TreeNode* root, int level, vector<vector<int>>& ret)
    {
        if (root == nullptr)
            return;
        if (ret.size() <= level)
            ret.push_back(vector<int>{});
        ret[level].push_back(root->val);
        zigzag(root->left, level + 1, ret);
        zigzag(root->right, level + 1, ret);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        zigzag(root, 0, ret);
        // 翻转奇数层
        int levels = ret.size();
        for (int it = 1; it < levels; it = it + 2)
            reverse(ret[it].begin(), ret[it].end());
        return ret;
    }
};
