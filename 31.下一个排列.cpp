/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (36.84%)
 * Likes:    1105
 * Dislikes: 0
 * Total Accepted:    162.4K
 * Total Submissions: 440.8K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须 原地 修改，只允许使用额外常数空间。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3]
 * 输出：[1,3,2]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [3,2,1]
 * 输出：[1,2,3]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,1,5]
 * 输出：[1,5,1]
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：nums = [1]
 * 输出：[1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // my solution
        int len = nums.size();
        if (len == 1) return;
        int r_min = nums[len - 1];

        for (int i = len - 2; i >= 0; --i) {
            if (nums[i] >= nums[i + 1]) continue;
            else {
                int k = len - 1;
                while (nums[k] <= nums[i]) --k;
                swap(nums[i], nums[k]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }

        reverse(nums.begin(), nums.end());
        return;
    }
};
// @lc code=end

