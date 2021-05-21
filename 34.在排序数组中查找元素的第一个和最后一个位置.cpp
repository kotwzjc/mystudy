/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (42.43%)
 * Likes:    1012
 * Dislikes: 0
 * Total Accepted:    255K
 * Total Submissions: 600.8K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 如果数组中不存在目标值 target，返回 [-1, -1]。
 * 
 * 进阶：
 * 
 * 
 * 你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 8
 * 输出：[3,4]
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [5,7,7,8,8,10], target = 6
 * 输出：[-1,-1]
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [], target = 0
 * 输出：[-1,-1]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -10^9 
 * nums 是一个非递减数组
 * -10^9 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // recommend solution
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            }
            else left = mid + 1;
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        // my solution
        /*
        int n = nums.size();
        int min_l = -1, max_r = -1, l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] != target) {
                    min_l = mid;
                    break;
                }
                else r = mid - 1;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (mid == n - 1 || nums[mid + 1] != target) {
                    max_r = mid;
                    break;
                }
                else l = mid + 1;
            }
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return {min_l, max_r};*/

        // recommend solution
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) 
            return vector<int>{leftIdx, rightIdx};

        return vector<int>{-1, -1};
    }
};
// @lc code=end

