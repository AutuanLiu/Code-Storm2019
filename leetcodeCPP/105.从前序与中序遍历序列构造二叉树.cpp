/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.57%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 30.6K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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

// 前序遍历的顺序 根左右
// 中序遍历的顺序 左根右
// 所以前序遍历的第一个节点就是二叉树的根节点
class Solution {
public:
    vector<int> preorders, inorders;
    // 注意这里的 pos 的位置是可以更改的
    // 因为 其在函数的内部发生了变化，递归过程中发生了变化
    TreeNode* build(int& pos, int lb, int rb)
    {
        // 递归出口, inorder全部访问完或者preorder全部访问完
        if (lb >= rb || pos >= preorders.size())
            return nullptr;
        TreeNode* root = new TreeNode(preorders[pos++]);
        // 找到当前 根节点 在 inorder 的位置
        int cur = lb;
        for (; cur < rb && inorders[cur] != root->val; cur++)
            ;

        // 递归左子树与右子树
        root->left = build(pos, lb, cur);
        root->right = build(pos, cur + 1, rb);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        // 赋值全局变量
        preorders = preorder;
        inorders = inorder;
        int pos = 0;
        TreeNode* root = build(pos, 0, inorder.size());
        return root;
    }
};

