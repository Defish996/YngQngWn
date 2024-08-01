//leetcode  昨日2的幂补充

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n < 1 ? false : (n & (n - 1)) == 0;
        //n & (n - 1) 有两种用法
        //1 判断一个数是不是2的幂
        //对于8 1000 和8-1 0111, 他们按位与的操作是0000
        //若为0 表明是2的幂
        //2 去除一个数二进制表示最右边的1
        //对于10 1010和10-1 1001, 他们按位与的操作是1000
        //去除了10的二进制表示最右边的1
    }
};

//leetcode24 两两交换链表中的节点
//递归法
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
    ListNode* swapPairs(ListNode* head) {
        //递归法
        if(head == nullptr || head->next == nullptr)//因为是两两交换, 所以递归退出条件为当前节点为nullptr或者是当前节点为最后一个节点
        {
            return head;
        }
        ListNode* tmp = swapPairs(head->next->next);//相信这个递归能将节点两两交换
        ListNode* res = head->next;//最后是返回head的下一个节点, 所以进行保存
        head->next->next = head;//怎么交换的实现
        head->next = tmp;
        return res;
    }
};

//迭代法
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newnode = new ListNode(0);//为链表创建一个哨兵位
        newnode->next = head;//链接哨兵位
        ListNode* temp = newnode;//重命名不破坏原结构
        while(temp->next && temp->next->next)//三个指针迭代, 至少两个不能为nullptr(不算哨兵位, 可以说是两个要交换的都不能为nullptr)
        {
            ListNode* node1 = temp->next;//后两个节点
            ListNode* node2 = temp->next->next;

            temp->next = node2;//进行迭代
            node1->next = node2->next;
            node2->next = node1;

            temp = node1;//准备赋给下一迭代
        }
        ListNode* ans = newnode->next;//打印结果
        delete newnode;
        newnode = nullptr;
        return ans;
    }
};