// leetcode 234. 回文链表

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
    bool isPalindrome(ListNode* head) {
        string s;
        while(head)
        {
            s += to_string(head->val);
            head = head->next;
        }
        string tmp;
        int size = s.size();
        for(int i = size - 1, j = 0; i >= size / 2; i--, j++)
        {
            tmp += s[i];
            s.pop_back();
        }
        if(size % 2 != 0)
        {
            tmp.pop_back();
        }
        return s == tmp;
    }
};