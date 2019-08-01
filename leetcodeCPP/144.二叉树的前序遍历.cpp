/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (60.14%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    30.5K
 * Total Submissions: 50.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
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
 * 输出: [1,2,3]
 * 
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
// 根左右
// 递归
// class Solution {
// public:
//     void preorder(TreeNode* root, vector<int>& nums)
//     {
//         if (root == nullptr)
//             return;
//         nums.push_back(root->val);
//         preorder(root->left, nums);
//         preorder(root->right, nums);
//     }

//     vector<int> preorderTraversal(TreeNode* root)
//     {
//         vector<int> ret;
//         preorder(root, ret);
//         return ret;
//     }
// };

// 非递归，迭代
// 使用 栈 来处理
// 由于栈是先进后出的所以要先把右子树压入栈中
// class Solution {
// public:
//     void preorder(TreeNode* root, vector<int>& ret)
//     {
//         // 特殊情况处理
//         if (root == nullptr)
//             return;
//         stack<TreeNode*> sk;
//         sk.push(root); // 先把 根 节点 压入栈中
//         // 循环进栈与出栈
//         while (!sk.empty()) {
//             // 先访问根节点
//             TreeNode* top = sk.top();
//             ret.push_back(top->val);
//             sk.pop(); // 访问完要删除

//             // 根据栈的先入后出原则，应该先把右子树加入栈中
//             // 才能保证 先访问左子树购访问右子树的顺序
//             if (top->right)
//                 sk.push(top->right);
//             if (top->left)
//                 sk.push(top->left);
//         }
//     }

//     vector<int> preorderTraversal(TreeNode* root)
//     {
//         vector<int> ret;
//         preorder(root, ret);
//         return ret;
//     }
// };


// 迭代方法的另一种写法
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& ret)
    {
        // 特殊情况处理
        if (root == nullptr)
            return;
        stack<TreeNode*> sk;

        // 循环进栈与出栈
        while (!sk.empty() || root) {
            if (root) {
                // 先访问根节点并入栈
                ret.push_back(root->val);
                sk.push(root);
                // 访问左子树
                root = root->left;
            } else {
                // 当左子树为空的时候，说明到达最左端，访问顺序就是 根左
                // 此时访问右子树
                TreeNode* top = sk.top();
                sk.pop(); // 访问完要删除
                root = top->right;
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        preorder(root, ret);
        return ret;
    }
};
