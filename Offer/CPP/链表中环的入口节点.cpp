// https: //leetcode-cn.com/problems/linked-list-cycle-ii/
// 使用集合实现
// class Solution {
// public:
//     ListNode* EntryNodeOfLoop(ListNode* head)
//     {
//         if (head == nullptr)
//             return head;
//         set<ListNode*> nodeset;
//         while (head) {
//             if (nodeset.find(head) != nodeset.end())
//                 return head;
//             nodeset.insert(head);
//             head = head->next;
//         }
//         return nullptr;
//     }
// };

// 快慢指针也可以做
// 慢指针一次走一步慢指针一次走两步
// 类似于在一个园里面 一个人走的快一个人走的慢 走的快的一定能在某个时刻追上走的慢的人
// 首先判断链表是否有环并计算环的长度
// 第二步 快指针先走环长度，慢指针在走，当他们相遇是，相遇的节点就是环的入口
// 时间复杂度太高