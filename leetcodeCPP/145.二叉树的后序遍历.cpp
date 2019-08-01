/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (65.87%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    23K
 * Total Submissions: 34.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
// class Solution {
// public:
//     void postorder(TreeNode* root, vector<int>& nums)
//     {
//         if (root == nullptr)
//             return;
//         postorder(root->left, nums);
//         postorder(root->right, nums);
//         nums.push_back(root->val);
//     }

//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ret;
//         postorder(root, ret);
//         return ret;
//     }
// };

// https://blog.csdn.net/zhangxiangDavaid/article/details/37115355
//  迭代版本
// 使用栈来实现
// 后序遍历的顺序是 左右根，而先序遍历的顺序是 根左右
// 将两者结合，那么可以访问 根右左，之后再进行反转，即可得到 正确的 后序遍历
// class Solution {
// public:
//     void postorder(TreeNode* root, vector<int>& ret)
//     {
//         if (root == nullptr)
//             return;
//         stack<TreeNode*> sk;
//         sk.push(root);
//         while(!sk.empty()) {
//             TreeNode* top = sk.top();
//             ret.push_back(top->val);
//             sk.pop();
            
//             // 根据先入后出的原则，先进栈的左子树 最后被访问
//             if (top->left)
//                 sk.push(top->left);
//             if (top->right)
//                 sk.push(top->right);
//         }
//     }

//     vector<int> postorderTraversal(TreeNode* root)
//     {
//         vector<int> ret;
//         postorder(root, ret);
//         // 这里对结果进行反转，即可得到后序遍历的结果
//         reverse(ret.begin(), ret.end());
//         return ret;
//     }
// };

// 上述思想的另外一种写法，一直访问根右，最后访问左子树
// class Solution {
// public:
//     void postorder(TreeNode* root, vector<int>& ret)
//     {
//         if (root == nullptr)
//             return;
//         stack<TreeNode*> sk;
//         while (!sk.empty() || root) {
//             // 一直按照 根右 的顺序进行访问
//             if (root) {
//                 ret.push_back(root->val);
//                 sk.push(root);
//                 root = root->right;
//             } else {
//                 TreeNode* top = sk.top();
//                 sk.pop();
//                 root = top->left;
//             }
//         }
//     }

//     vector<int> postorderTraversal(TreeNode* root)
//     {
//         vector<int> ret;
//         postorder(root, ret);
//         // 这里对结果进行反转，即可得到后序遍历的结果
//         reverse(ret.begin(), ret.end());
//         return ret;
//     }
// };

// 二叉树的每个节点都可以当做是 根节点

// 不使用技巧（后序遍历和先序遍历的关系）直接使用标记法来标记当前节点的右子树是否被访问
// 只有当当前节点的右子树被访问过会后，当前节点才能被访问
// 使用一个辅助指针用于表示上一次访问的节点
// 只有当上一次访问的节点是当前节点的右节点时，当前节点才能够被访问
class Solution {
public:
    void postorder(TreeNode* root, vector<int>& ret)
    {
        if (root == nullptr)
            return;
        stack<TreeNode*> sk;
        TreeNode* last = nullptr;
        while (!sk.empty() || root) {
            if (root) {
                sk.push(root);
                root = root->left;
            } else {
                TreeNode* top = sk.top();
                // 判断右节点是否已经被访问过
                // 如果右节点存在并且没有被访问过，那么就访问
                if (top->right && top->right != last) {
                    root = top->right;
                } else {
                    // 只有当当前节点的右节点已经访问过了 才访问当前节点并出栈
                    ret.push_back(top->val);
                    sk.pop();

                    // 记录上次访问的节点，当前节点已经访问过了，那么就进行下一次循环，
                    // 置root为nullptr表示已经访问过
                    last = top;
                    root = nullptr;
                }
            }
        }
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        postorder(root, ret);
        return ret;
    }
};
