/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-root_postorder-traversal/description/
 *
 * algorithms
 * Medium (61.48%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    10.9K
 * Total Submissions: 17.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 root_postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    vector<int> root_postorders, inorders;
    // 注意这里的 root_pos 的位置是可以更改的
    // 因为 其在函数的内部发生了变化，递归过程中发生了变化
    TreeNode* build(int& root_pos, int lb, int rb)
    {
        // 递归出口, inorder全部访问完或者root_postorder全部访问完
        if (lb >= rb || root_pos >= root_postorders.size())
            return nullptr;
        TreeNode* root = new TreeNode(root_postorders[root_pos--]);
        // 找到当前 根节点 在 inorder 的位置
        int cur = lb;
        for (; cur < rb && inorders[cur] != root->val; cur++)
            ;

        // 递归左子树与右子树
        // 根右  右根  按照后序遍历的顺序访问 从右到左  分别是  根右左
        // 后序遍历的访问顺序是 左右根 但是，我们是按照后序遍历数组从右到左的顺序进行构建
        // 所有，递归构建的顺序应该是 根右左
        root->right = build(root_pos, cur + 1, rb);
        root->left = build(root_pos, lb, cur);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& root_postorder)
    {
        // 赋值全局变量
        root_postorders = root_postorder;
        inorders = inorder;
        int root_pos = root_postorder.size() - 1;
        TreeNode* root = build(root_pos, 0, inorder.size());
        return root;
    }
};
