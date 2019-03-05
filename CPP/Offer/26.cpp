class Solution
{
  public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        TreeNode *pList = nullptr; //链表的头节点
        preoder(pRootOfTree, &pList);
        return pList;
    }
    void preoder(TreeNode *pRootOfTree, TreeNode **pList) //先序遍历的反向遍历 --右->中->左
    {
        if (pRootOfTree == nullptr)
            return;
        if (pRootOfTree->right != nullptr)
            preoder(pRootOfTree->right, pList);

        pRootOfTree->right = *pList;
        if (*pList != nullptr)
            (*pList)->left = pRootOfTree;
        *pList = pRootOfTree;

        if (pRootOfTree->left != nullptr)
            preoder(pRootOfTree->left, pList);
    }
};

class Solution
{
  public:
    TreeNode *Convert(TreeNode *pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        TreeNode *pointer = NULL;
        convert2List(pRootOfTree, pointer);
        while (pointer->left != NULL)
        {
            pointer = pointer->left;
        }
        return pointer;
    }
    void convert2List(TreeNode *pRoot, TreeNode *&pointer)
    {
        if (pRoot == NULL)
        {
            return;
        }
        {
            if (pRoot->left != NULL)
            {
                convert2List(pRoot->left, pointer);
            }

            pRoot->left = pointer;
            if (pointer != NULL)
            {
                pointer->right = pRoot;
            }

            pointer = pRoot;
            if (pRoot->right != NULL)
            {
                convert2List(pRoot->right, pointer);
            }
        }
    }
};
