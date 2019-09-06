// 复杂链表的复制.cpp
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        RandomListNode* cur = pHead;
        while (cur) {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        } //直到cur指向了原先链表的结尾null处
        cur = pHead;
        RandomListNode* p;
        while (cur) {
            p = cur->next;
            if (cur->random) {
                p->random = cur->random->next;
            }
            cur = p->next;
        }

        RandomListNode* pCloneHead = pHead->next;
        RandomListNode* tmp;
        cur = pHead;
        while (cur->next) {
            tmp = cur->next;
            cur->next = tmp->next;
            cur = tmp;
        }
        return pCloneHead;
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return NULL;

        //定义一个哈希表
        unordered_multimap<RandomListNode*, RandomListNode*> table;

        // 开辟一个头结点
        RandomListNode* pClonedHead = new RandomListNode(pHead->label);
        pClonedHead->next = NULL;
        pClonedHead->random = NULL;

        // 将头结点放入map中
        table.insert(make_pair(pHead, pClonedHead));

        //设置操作指针
        RandomListNode* pNode = pHead->next;
        RandomListNode* pClonedNode = pClonedHead;

        // 第一遍先将简单链表复制一下
        while (pNode != NULL) {
            // 不断开辟pNode的拷贝结点
            RandomListNode* pClonedTail = new RandomListNode(pNode->label);
            pClonedTail->next = NULL;
            pClonedTail->random = NULL;

            //连接新节点，更新当前节点
            pClonedNode->next = pClonedTail;
            pClonedNode = pClonedTail;

            //将对应关系  插入到哈希表中
            table.insert(make_pair(pNode, pClonedTail));

            //向后移动操作节点
            pNode = pNode->next;
        }

        //需从头开始设置random节点，设置操作指针
        pNode = pHead;
        pClonedNode = pClonedHead;

        // 根据map中保存的数据，找到对应的节点
        while (pNode != NULL) {

            if (pNode->random != NULL) {
                //找到对应节点，更新复制链表
                pClonedNode->random = table.find(pNode->random)->second;
            }

            //向后移动操作节点
            pNode = pNode->next;
            pClonedNode = pClonedNode->next;
        }

        return pClonedHead;
    }
};
