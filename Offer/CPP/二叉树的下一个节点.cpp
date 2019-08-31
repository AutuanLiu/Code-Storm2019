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
        // 当前节点是空节点
        if (pNode == nullptr)
            return nullptr;
        TreeLinkNode* pNext = nullptr;
        // 存在右子树 找到右子树的最左孩子
        if (pNode->right != nullptr) {
            pNext = pNode->right;
            while (pNext->left != nullptr) {
                pNext = pNext->left;
            }
        } else if (pNode->right == nullptr && pNode->next != nullptr) {
            // 如果当前节点是其父节点的左子节点那么其中序遍历的下一个节点就是其父节点
            // 如果当前节点是其父节点的右子节点，其下一个节点是当前节点所在的左子树的根
            TreeLinkNode* cur = pNode;
            TreeLinkNode* pNodeParent = pNode->next;
            while (pNodeParent != nullptr && cur == pNodeParent->right) {
                cur = pNodeParent;
                pNodeParent = pNodeParent->next;
            }
            pNext = pNodeParent;
        }
        return pNext;
    }
};
