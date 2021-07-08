/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 *
 * https://leetcode-cn.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (41.30%)
 * Likes:    1116
 * Dislikes: 0
 * Total Accepted:    139.9K
 * Total Submissions: 337.9K
 * Testcase Example:  '[1,2,0]'
 *
 * 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
 * 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,0]
 * 输出：3
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,4,-1,1]
 * 输出：2
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [7,8,9,11,12]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -2^31 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // my solution
        /*int l = nums.size();
        vector<int> hash_table(l, 0);

        for (int i = 0; i < l; ++i) {
            if (nums[i] < 1 || nums[i] > l) continue;
            hash_table[nums[i] - 1] = 1;
        }

        for (int i = 0; i < l; ++i) {
            if (hash_table[i] == 0) return i + 1;
        }
        return l + 1;*/

        // 哈希表
        /*int n = nums.size();

        for (int& num: nums) {
            if (num <= 0) {
                num = n + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            int num = abs(nums[i]);
            if (num <= n) nums[num - 1] = -abs(nums[num - 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) return i + 1;
        }

        return n + 1;*/

        // 置换
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) 
                swap(nums[i], nums[nums[i] - 1]);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        return n + 1;
    }
};
// @lc code=end

