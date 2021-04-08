/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // my solution
        /*
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > target && nums[i] > 0) return ans;
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int tmp = nums[i] + nums[left] + nums[right];
                ans = abs(tmp - target) < abs(ans - target) ? tmp : ans;
                if (tmp < target) left++;
                else if (tmp > target) right--;
                else return target;
            }
        }

        return ans;*/

        // recommend solution
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) best = cur;
        };

        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) return sum;
                update(sum);
                if (sum > target) {
                    int k0 = k - 1;
                    while (j < k0 && nums[k0] == nums[k]) --k0;
                    k = k0;
                } else {
                    int j0 = j + 1;
                    while (j0 < k && nums[j0] == nums[j]) ++j0;
                    j = j0;
                }
            }
        }

        return best;
    }
};
// @lc code=end

