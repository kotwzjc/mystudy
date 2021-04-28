/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-04-24 21:04:46
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-04-25 20:41:18
 */
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (69.47%)
 * Likes:    895
 * Dislikes: 0
 * Total Accepted:    250.9K
 * Total Submissions: 360.9K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4]
 * 输出：[2,1,4,3]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目在范围 [0, 100] 内
 * 0 
 * 
 * 
 * 
 * 
 * 进阶：你能在不修改链表节点值的情况下解决这个问题吗?（也就是说，仅修改节点本身。）
 * 
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
    ListNode* swapPairs(ListNode* head) {
        // my solution
        /*
        if (head == nullptr) return nullptr;
        ListNode *ans = new ListNode(0, head);
        ListNode *pre = ans, *node1 = head, *node2 = head->next;

        while (node2 != nullptr) {
            node1->next = node2->next;
            node2->next = node1;
            pre->next = node2;
            
            pre = node1;
            node1 = node1->next;
            if (node1 == nullptr) break;
            node2 = node1->next;
        }

        return ans->next;*/

        // 递归
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;
        return newHead;
    }
};
// @lc code=end

