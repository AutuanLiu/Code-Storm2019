// 二叉树的中序遍历的下一个节点
struct TreeLinkNode {
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
        , next(NULL)
    {
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {

    }
};