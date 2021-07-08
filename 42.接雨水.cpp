/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (56.25%)
 * Likes:    2453
 * Dislikes: 0
 * Total Accepted:    266.8K
 * Total Submissions: 473.7K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 
 * 输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出：6
 * 解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：height = [4,2,0,3,2,5]
 * 输出：9
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * n == height.length
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // my solution
        /*int n = height.size();
        int ans = 0;
        if (n < 3) return ans;
        int left = 0, right = 0;
        int ori_left = 0;
        while (ori_left < n && height[ori_left] == 0) ori_left++;
        if (ori_left == n) return ans;
        bool modified = false;
        left = ori_left;

        while (true) {
            while (left + 1 < n && height[left + 1] >= height[left]) left++;
            if (left == n - 1) {
                if (modified) {
                    left = ori_left;
                    modified = false;
                    continue; 
                }
                else break;
            }

            while (left + 1 < n && height[left + 1] < height[left]) left++;
            if (left == n - 1) {
                if (modified) {
                    left = ori_left;
                    modified = false;
                    continue;
                }
                else break;
            }
            right = left + 1;
            left = left - 1;

            while (right + 1 < n && height[right + 1] >= height[right]) right++;
            int h = height[left] < height[right] ? height[left] : height[right];
            for (int i = left + 1; i < right; i++) {
                if (h > height[i]) {
                    ans += h - height[i];
                    height[i] = h;
                    modified = true;
                }
            }

            if (right == n - 1) {
                if (!modified) break;

                left = ori_left;
                modified = false;
            }
            else left = right;
        }

        return ans;*/

        // 动态编程
        /*int n = height.size();
        int ans = 0;
        if (n < 3) return ans;
        vector<int> left_max(n), right_max(n);
        left_max[0] = height[0];
        for (int i = 1; i < n; ++i) left_max[i] = max(height[i], left_max[i - 1]);
        right_max[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; --j) right_max[j] = max(height[j], right_max[j + 1]);

        for (int i = 1; i < n - 1; ++i) 
            ans += min(left_max[i], right_max[i]) - height[i];
        
        return ans;*/

        // 栈
        /*int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int bound_height = min(height[st.top()], height[current]) - height[top];
                int distance = current - st.top() - 1;
                ans += distance * bound_height;
            }
            st.push(current);
            current++;
        }

        return ans;*/

        // 双指针
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;

        while (left <= right) {
            if (left_max < right_max) {
                ans += max(0, left_max - height[left]);
                left_max = max(left_max, height[left]);
                left++;
            }
            else {
                ans += max(0, right_max - height[right]);
                right_max = max(right_max, height[right]);
                right--;
            }
        }

        return ans;
    }
};
// @lc code=end

