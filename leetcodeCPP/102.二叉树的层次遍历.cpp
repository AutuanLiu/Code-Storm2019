/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (56.72%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 61.3K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
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
// 用队列来实现层序遍历
// 深度优先搜索策略又可以根据根节点、左孩子和右孩子的相对顺序被细分为先序遍历，中序遍历和后序遍历
// 宽度优先搜索（BFS）我们按照高度顺序一层一层的访问整棵树，高层次的节点将会比低层次的节点先被访问到

// 迭代法实现
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root)
//     {
//         vector<vector<int>> ret;
//         if (root == nullptr)
//             return {};
//         queue<TreeNode*> qe;
//         qe.push(root);
//         while (!qe.empty()) {
//             // 一层一层的访问
//             // 记录当前层的元素和个数
//             vector<int> tmp;
//             int n = qe.size();
//             for (int i = 0; i < n; i++) {
//                 TreeNode* front = qe.front();
//                 tmp.push_back(front->val);
//                 qe.pop();
//                 if (front->left)
//                     qe.push(front->left);
//                 if (front->right)
//                     qe.push(front->right);
//             }
//             ret.push_back(tmp);
//         }
//         return ret;
//     }
// };

// 递归实现
class Solution {
public:
    void levelVisit(TreeNode* root, int level, vector<vector<int>>& ret)
    {
        // 如果 root 为空
        if (root == nullptr)
            return;
        // 判断什么时候进入新的一层
        // 当 ret的数组数小于等于层数的时候
        // 有多少层就应该有多少个数组
        if (ret.size() <= level)
            ret.push_back(vector<int>{});

        // 相当于先序遍历（DFS），只是多了一个层数判断
        ret[level].push_back(root->val);
        levelVisit(root->left, level + 1, ret);
        levelVisit(root->right, level + 1, ret);
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ret;
        levelVisit(root, 0, ret);
        return ret;
    }
};
