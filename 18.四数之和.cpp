/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (40.15%)
 * Likes:    808
 * Dislikes: 0
 * Total Accepted:    170.3K
 * Total Submissions: 424K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：答案中不可以包含重复的四元组。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,0,-1,0,-2,2], target = 0
 * 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // my solution
        vector<vector<int>> result;
        int len = nums.size();

        if(len < 4) return result;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 3; ++i) {
            if (nums[i] > target && nums[i] > 0) return result;
            if (i > 0 && nums[i - 1] == nums[i]) continue;

            for (int j = i + 1; j < len - 2; ++j) {
                if (j > i + 1 && nums[j - 1] == nums[j]) continue;
                int left = j + 1, right = len - 1;

                while (left < right) {
                    int tmp = nums[i] + nums[j] + nums[left] + nums[right];
                    if (tmp < target) left++;
                    else if (tmp > target) right--;

                    else {
                        vector<int> ans = {nums[i], nums[j], nums[left], nums[right]};
                        result.push_back(ans);

                        int new_left = left + 1, new_right = right - 1;
                        while(new_left < right && nums[new_left] == nums[left]) new_left++;
                        while(new_right > left && nums[new_right] == nums[right]) new_right--;
                        left = new_left;
                        right = new_right;
                    }
                }
            }
        }

        return result;
    }
};
// @lc code=end

