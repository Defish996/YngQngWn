// LCR 077. 排序链表 分治 递归

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
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }
    ListNode* sortList(ListNode* head, ListNode* tail)
    {
        if(head == nullptr) return head;// 空节点自然有序, 无需进行多余操作
        if(head->next == tail)// 分治到只剩一个节点时进行拆分
        {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;// 用于找中间节点
        while(fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast != tail) fast = fast->next;
        }
        ListNode* mid = slow;

        return merge(sortList(head, mid), sortList(mid, tail));// 进行分治后的排序操作
    }
    
    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        ListNode* ans = new ListNode(0);// 用于返回结果的新头节点
        ListNode* temp = ans, *temp1 = head1, *temp2 = head2;// 存放节点头信息用于返回
        while(temp1 != nullptr && temp2 != nullptr)// 进行排序
        {
            if(temp1->val <= temp2->val)// 进行单节点的链接, 主节点和子节点分别先后移动
            {
                temp->next = temp1;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if(temp1 != nullptr) temp->next = temp1;//子链表中的任意一个为空时链接另一个链表
        else if(temp2 != nullptr) temp->next = temp2;
        return ans->next;
    }
};