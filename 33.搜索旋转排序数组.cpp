/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (41.62%)
 * Likes:    1362
 * Dislikes: 0
 * Total Accepted:    279.5K
 * Total Submissions: 670.2K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 整数数组 nums 按升序排列，数组中的值 互不相同 。
 * 
 * 在传递给函数之前，nums 在预先未知的某个下标 k（0 ）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ...,
 * nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如，
 * [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
 * 
 * 给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 0
 * 输出：4
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,5,6,7,0,1,2], target = 3
 * 输出：-1
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1], target = 0
 * 输出：-1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * -10^4 
 * nums 中的每个值都 独一无二
 * 题目数据保证 nums 在预先未知的某个下标上进行了旋转
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：你可以设计一个时间复杂度为 O(log n) 的解决方案吗？
 * 
 */

// @lc code=start
class Solution {
public:
    int binSearch(vector<int>& nums, int left, int right, int target) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return binSearch(nums, mid + 1, right, target);
        else return binSearch(nums, left, mid - 1, target);

    }


    int search(vector<int>& nums, int target) {
        // my solution
        /*
        if (nums.size() == 1) {
            if (nums[0] == target) return 0;
            return -1;
        }
        int k, nums_len = nums.size();

        if (nums[nums_len - 1] > nums[0]) k = 0;
        else {
            int left = 0, right = nums_len - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                mid = mid > 0 ? mid : 1;
                if (nums[mid - 1] > nums[mid]) {
                    k = mid;
                    break;
                }
                else if (nums[mid] > nums[0]) left = mid + 1;
                else right = mid - 1;
            }
        }

        if (nums[nums_len - 1] == target) return nums_len - 1;
        else if (nums[nums_len - 1] < target) return binSearch(nums, 0, k - 1, target);
        else return binSearch(nums, k, nums_len - 1, target);
        */

       // recommend solution
       int n = (int)nums.size();
       if (!n) return -1;
       if (n == 1) return nums[0] == target ? 0 : -1;

       int l = 0, r = n - 1;
       while (l <= r) {
           int mid = (l + r) / 2;
           if (nums[mid] == target) return mid;
           if (nums[l] <= nums[mid]) {
               if (nums[l] <= target && target < nums[mid]) r = mid - 1;
               else l = mid + 1;
           }
           else {
               if (nums[mid] < target && nums[r] >= target) l = mid + 1;
               else r = mid - 1;
           }
       }

       return -1;
    }
};
// @lc code=end

