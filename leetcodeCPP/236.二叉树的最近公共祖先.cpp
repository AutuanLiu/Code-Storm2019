/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 *
 * https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (55.17%)
 * Likes:    209
 * Dislikes: 0
 * Total Accepted:    19.2K
 * Total Submissions: 34.3K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x
 * 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 * 
 * 
 * 
 * 
 * 说明:
 * 
 * 
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* sub_left = lowestCommonAncestor(root->left, p, q);
        TreeNode* sub_right = lowestCommonAncestor(root->right, p, q);

        // 左子树已经遍历完，没有找到 p, q 说明 p, q 都在右子树
        // 那么先找到的那个就是 公共祖先节点
        if (sub_left == nullptr)
            return sub_right;

        // 右子树已经遍历完，没有找到 p, q 说明 p, q 都在左子树
        // 那么先找到的那个就是 公共祖先节点
        else if (sub_right == nullptr)
            return sub_left;

        // 左右子树都不为空，说明两个节点分散在二叉树的两侧
        // 这个时候，当前节点就是 最近公共节点，因为两个节点刚好分散在该节点的两侧
        else
            return root;
    }
};
