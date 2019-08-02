/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (53.93%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    30.2K
 * Total Submissions: 55.9K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
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
//  */
// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q)
//     {
//         // 两个树都是空的，则是相同的树
//         if ((p == nullptr && q == nullptr))
//             return true;

//         // 如果有其中的一个树是空的，那么一定是 False
//         if (p == nullptr || q == nullptr)
//             return false;

//         // 只有 p 和 q 都不为空才进行下述判断
//         assert(p && q);
//         if (p->val != q->val)
//             return false;
//         // 左右子树同时相等,两个树才相等
//         return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//     }
// };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        // 两个树都是空的，则是相同的树
        if ((p == nullptr && q == nullptr))
            return true;

        // 如果有其中的一个树是空的，那么一定是 False
        // 只有当两个不为 nullptr的时候才会有 val, keft, right 等这些指针
        if (p != nullptr && q != nullptr && p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else
            return false;
    }
};
