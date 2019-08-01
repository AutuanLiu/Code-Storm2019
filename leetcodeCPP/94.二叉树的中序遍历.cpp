/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (66.14%)
 * Likes:    236
 * Dislikes: 0
 * Total Accepted:    44.8K
 * Total Submissions: 66.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    void inorder(TreeNode* root, vector<int>& ret)
    {
        if (root == nullptr)
            return;
        stack<TreeNode*> sk;

        // 循环结束的条件有两个，一个是栈为空，另一个是所有的节点都已经访问了
        while (!sk.empty() || root) {
            // 先访问到坐左边的节点
            if (root) {
                sk.push(root); // 进栈
                root = root->left; // 一直访问到最左端的节点
            } else {
                // 当root为空说明已经访问到最左边的节点了
                // 也即没有左子节点，此时的栈顶元素代表了根节点
                // 此时可以出栈
                TreeNode* top = sk.top(); // 最左边的节点, 这里的保存时为了后面访问右子树
                ret.push_back(top->val);
                sk.pop();

                // 如果根节点存在右子树，继续访问右子树，重复上述过程
                root = top->right;
            }
        }
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        inorder(root, ret);
        return ret;
    }
};
