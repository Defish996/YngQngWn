// 判断俩链表是否相交 双指针 hash

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* curA = headA;
//         ListNode* curB = headB;
//         unordered_set<ListNode* > hash;
//         while(curA)
//         {
//             hash.insert(curA);
//             curA = curA->next;
//         }
//         while(curB)
//         {
//             if(hash.count(curB))
//             {
//                 return curB;
//             }
//             curB = curB->next;
//         }
//         return nullptr;
//     }
// };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != curB)
        {
            curA = curA == nullptr ? headB : curA->next;
            curB = curB == nullptr ? headA : curB->next;
        }
        return curA;
    }
};