//leetcode 206链表逆置 递归法

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //递归解决
        if(head == nullptr || head->next == nullptr)//为空或者为叶子结点就返回当前节点
        {
            return head;
        }
        ListNode* newnode = reverseList(head->next);//newhead接受逆置后的结果

        //把自己添加到这个链表
        head->next->next= head;//已经逆置完成, 让下个节点的next指向我
        head->next = nullptr;//我指向空

        return newnode;//返回逆置后的头节点
    }
};