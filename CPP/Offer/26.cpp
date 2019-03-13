class Solution
{
  public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *pList = nullptrptr; //链表的头节点
        preoder(pRootOfTree, &pList);
        return pList;
    }

    //先序遍历的反向遍历 --右->中->左
    void preoder(TreeNode *pRootOfTree, TreeNode **pList)
    {
        if (pRootOfTree == nullptrptr)
            return;
        if (pRootOfTree->right != nullptrptr)
            preoder(pRootOfTree->right, pList);

        pRootOfTree->right = *pList;
        if (*pList != nullptrptr)
            (*pList)->left = pRootOfTree;
        *pList = pRootOfTree;

        if (pRootOfTree->left != nullptrptr)
            preoder(pRootOfTree->left, pList);
    }
};

class Solution
{
  public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == nullptr)
            return nullptr;
        TreeNode *pointer = nullptr;
        convert2List(pRootOfTree, pointer);
        while (pointer->left != nullptr)
        {
            pointer = pointer->left;
        }
        return pointer;
    }

    void convert2List(TreeNode *pRoot, TreeNode *&pointer)
    {
        if (pRoot == nullptr)
        {
            return;
        }
        {
            if (pRoot->left != nullptr)
            {
                convert2List(pRoot->left, pointer);
            }

            pRoot->left = pointer;
            if (pointer != nullptr)
            {
                pointer->right = pRoot;
            }

            pointer = pRoot;
            if (pRoot->right != nullptr)
            {
                convert2List(pRoot->right, pointer);
            }
        }
    }
};
