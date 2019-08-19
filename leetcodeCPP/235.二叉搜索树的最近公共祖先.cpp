/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (59.63%)
 * Likes:    138
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 31.9K
 * Testcase Example:  '[6,2,8,0,4,7,9,null,null,3,5]\n2\n8'
 *
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉搜索树:  root = [6,2,8,0,4,7,9,null,null,3,5]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 * 输出: 6 
 * 解释: 节点 2 和节点 8 的最近公共祖先是 6。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 * 输出: 2
 * 解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉搜索树中。
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

// 这里是 二叉搜索树，左边的都比根小，右边的都比根大
// 节点 NN 左子树上的所有节点的值都小于等于节点 NN 的值
// 节点 NN 右子树上的所有节点的值都大于等于节点 NN 的值
// 左子树和右子树也都是 BST

// 所以 最近公共祖先就是 有一个数值比 根小，一个数值比根大
// 或者是都比根大或者根小 那么其中的一个节点就是最小的公共祖先节点

// 递归的方案
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//     {
//         // 把重复使用的数值拿出来，可以加速
//         int v_r = root->val, v_p = p->val, v_q = q->val;
//         if (v_p > v_r && v_q > v_r)
//             // 说明在右子树
//             return lowestCommonAncestor(root->right, p, q);
//         else if (v_p < v_r && v_q < v_r)
//             // 在左子树
//             return lowestCommonAncestor(root->left, p, q);
//         else
//             return root;
//     }
// };

// 非递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        // 把重复使用的数值拿出来，可以加速
        int v_p = p->val, v_q = q->val;
        while (root) {
            int v_r = root->val;
            if (v_p > v_r && v_q > v_r)
                // 说明在右子树
                root = root->right;
            else if (v_p < v_r && v_q < v_r)
                // 在左子树
                root = root->left;
            else
                return root;
        }
        return nullptr;
    }
};
