/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (54.84%)
 * Likes:    1267
 * Dislikes: 0
 * Total Accepted:    244.5K
 * Total Submissions: 445.7K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 * 
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 * 
 * 
 * 示例 2：
 * 
 * 输入：lists = []
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 输入：lists = [[]]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
    // my solutioin1
    /*
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }*/

    // 分治合并
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if ((!a) || (!b)) return a ? a : b;
        ListNode head, *tail = &head, *aPtr=a, *bPtr=b;
        while (aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    // 分治合并
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l == r) return lists[l];
        if (l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // my solution1 最后一个超时
        /*
        int k = lists.size();
        if (k == 0) return nullptr;
        unordered_map<int, ListNode*> iterators;
        ListNode* ans = new ListNode();
        ListNode* node = ans;
        vector<vector<int>> nums;

        for (int i = 0; i < k; ++i)
            if (lists[i] != nullptr) {
                iterators[i] = lists[i];
                vector<int> tmp = {i, lists[i]->val};
                nums.push_back(tmp);
            }

        sort(nums.begin(), nums.end(), cmp);

        while (iterators.size() > 1) {
            auto t = nums.begin();
            int index = (*t)[0];
            nums.erase(t);

            node->next = iterators[index];
            node = node->next;

            iterators[index] = iterators[index]->next;
            if (iterators[index] == nullptr) iterators.erase(index);
            else {
                int num = iterators[index]->val;
                auto it = nums.begin();
                vector<int> ins = {index, num};

                for (; it != nums.end(); ++it) 
                    if (num < (*it)[1]) {
                        nums.insert(it, ins);
                        break;
                    }

                if (it == nums.end()) nums.push_back(ins);
            }
        }

        if (iterators.size() == 1) node->next = iterators.begin()->second;
        return ans->next;*/

        // my solution2 直接暴力
        /*
        int k = lists.size();
        if (k == 0) return nullptr;
        ListNode* ans = new ListNode();
        ListNode* node = ans;
        vector<int> nums;

        for (int i = 0; i < k; ++i) {
            ListNode* tmp = lists[i];
            while (tmp != nullptr) {
                nums.push_back(tmp->val);
                tmp = tmp->next;
            }
        }

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            ListNode* ins = new ListNode(nums[i]);
            node->next = ins;
            node = node->next;
        }

        return ans->next;*/

        // 分治合并
        return merge(lists, 0, lists.size() - 1);
    }
};
// @lc code=end

