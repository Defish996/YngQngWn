// 复习, 链表有环和找出那个环节点

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;// 注意刚开始的head为当前和他的下一个
        ListNode* fast = head->next;//初始化
        ListNode* slow = head;
        while(slow != fast)// 条件建议为不相等时
        {
            if(fast == nullptr || fast->next == nullptr ) return false;// 先进行判断fast为两步, 所以要针对fast进行判定
            slow = slow->next;
            fast = fast->next->next;
            
        }
        return true;// 相等跳出循环为有环
    }
};

//环链表的环节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        ListNode* fast = head;// 推荐使用这样的方式让快慢指针进行初始化, 而不是像上面那样将跳过一个节点, 
								//这样虽然也能判断出来是否带环, 但是在找寻找这个环节点的过程中, 寻找的节点就有可能出错, 所以还是推荐初始化进行初始化为head节点
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr;
    }
};