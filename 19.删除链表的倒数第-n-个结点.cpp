/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // my solution 双指针
        /*
        ListNode* tmp = head;
        ListNode* pre = head;
        int count = 0, num = 1;

        while (tmp->next != nullptr && count < n) {
            tmp = tmp->next;
            ++count;
            ++num;
        }

        while (tmp->next != nullptr) {
            tmp = tmp->next;
            pre = pre->next;
            ++num;
        }

        if (n == num) return head->next;
        pre->next = pre->next->next;
        return head;*/

        // 栈
        ListNode* dummy = new ListNode(0, head);
        stack<ListNode*> stk;
        ListNode* cur = dummy;

        while (cur) {
            stk.push(cur);
            cur = cur->next;
        }
        for (int i = 0; i < n; ++i) stk.pop();
        
        ListNode* pre = stk.top();
        pre->next = pre->next->next;
        ListNode* ans = dummy->next;
        return ans;
    }
};
// @lc code=end

