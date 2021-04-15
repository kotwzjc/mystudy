/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-04-15 19:51:27
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-04-15 20:50:02
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (65.80%)
 * Likes:    1668
 * Dislikes: 0
 * Total Accepted:    538.4K
 * Total Submissions: 818.2K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [1,2,4], l2 = [1,3,4]
 * 输出：[1,1,2,3,4,4]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [], l2 = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 两个链表的节点数目范围是 [0, 50]
 * -100 
 * l1 和 l2 均按 非递减顺序 排列
 * 
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // my solution
        /*
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr || l2 == nullptr) return l1 ? l1 : l2;

        if (l1->val > l2->val) {
            ListNode* tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        ListNode* node1 = l1->next;
        ListNode* node2 = l2;
        ListNode* pre = l1;

        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val <= node2->val) {
                node1 = node1->next;
                pre = pre->next;
            }
            else {
                ListNode* tmp = node2->next;
                node2->next = node1;
                pre->next = node2;
                node2 = tmp;
                pre = pre->next;
            }
        }

        if (node2 != nullptr) pre->next = node2;

        return l1;*/

        // 递归
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        else if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// @lc code=end

