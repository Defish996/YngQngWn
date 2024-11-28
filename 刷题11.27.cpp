// 128. 最长连续序列 hash


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(auto &e : nums)
        {
            set.insert(e);
        }// 放入set

        int max_len = 0;
        for(const int & e : set)
        {
            if(!set.count(e - 1))// 前一个不在就说明需要进行遍历, 如果在, 说明已经在前一个之前的元素的遍历中已经处理过了
            {
                int len = 1;
                int curnum = e;
                while(set.count(curnum + 1))// 找当前的下一个在不在
                {
                    ++len;
                    ++curnum;
                }
                max_len = max(len, max_len);// 不在就进行当前与历史的最大len
            }
        }
        return max_len;
    }
};

// 合并两个有序链表 递归 迭代

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

// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == nullptr || list2 == nullptr)
//         {
//             return list1 == nullptr ? list2 : list1;
//         }
//         if(list1->val < list2->val)
//         {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
//         else
//         {
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//         return nullptr;
//     }
// };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr || list2 == nullptr) {
            return list1 == nullptr ? list2 : list1;
        }
        ListNode* ret = new ListNode;// 用于返回, 指向第一个节点的地址
        ListNode* ans = ret;// 指针用于遍历这个新建的链表
        while (list1 && list2) {
            if (list1->val < list2->val) {
                ans->next = list1;// 节点
                list1 = list1->next;// 指针
            } else {
                ans->next = list2;
                list2 = list2->next;
            }
            ans = ans->next;
        }
        if(list1 == nullptr || list2 == nullptr)
        {
            ans->next = list1 == nullptr ? list2 : list1;
        }
        return ret->next;// 返回下一个
    }
};