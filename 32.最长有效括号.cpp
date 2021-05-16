/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (34.86%)
 * Likes:    1295
 * Dislikes: 0
 * Total Accepted:    149.3K
 * Total Submissions: 428K
 * Testcase Example:  '"(()"'
 *
 * 给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "(()"
 * 输出：2
 * 解释：最长有效括号子串是 "()"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = ")()())"
 * 输出：4
 * 解释：最长有效括号子串是 "()()"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * s[i] 为 '(' 或 ')'
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // my solution, very slowly
        /*
        if (s.length() < 2) return 0;
        int s_len = s.length();
        int ans = 0, preEnd = -1, preLen = 0;
        vector<int> visited(s_len, 0);
        vector<int> tmpLen(s_len, 0);

        for (int i = 0; i < s_len; ++i) {
            while (i < s_len && s[i] != ')') i++;
            if (i == s_len) break;
            visited[i] = 1;
            if (i == 0) continue;

            int left = i - 1;
            while (left >= 0 && visited[left] == 1) left--;
            if (left < 0) continue;
            visited[left] = 1;

            if (preEnd + 1 == left) {
                preLen += 2;
                preEnd = i;
                tmpLen[preEnd - preLen + 1] = preLen;
            }
            else if (left + preLen == preEnd || left + 1 == i) {
                preEnd = i;
                preLen = i - left + 1;
                tmpLen[preEnd - preLen + 1] = preLen;
            }
            else {
                for (int i = 0; i < s_len; ++i) {
                    if (tmpLen[i] == 0) continue;
                    int tmp = i;
                    while (i < s_len && tmpLen[i] > 0) i += tmpLen[i];
                    tmpLen[tmp] = i - tmp;
                }
                if (left + tmpLen[left + 1] + 1 == i) {
                    preEnd = i;
                    preLen = i - left + 1;
                    tmpLen[preEnd - preLen + 1] = preLen;
                }
                else visited[left] = 0;
            }
            
            ans = ans > preLen ? ans : preLen;
        }

        for (int i = 0; i < s_len; ++i) {
            if (tmpLen[i] == 0) continue;
            int tmp = i;
            while (i < s_len && tmpLen[i] > 0) i += tmpLen[i];
            tmp = i - tmp;
            ans = ans > tmp ? ans : tmp;
        }

        return ans;*/

        // 动态规划
        /*
        int s_len = s.length();
        if (s_len < 2) return 0;
        vector<int> dp(s_len, 0);
        int ans = 0;

        for (int i = 1; i < s_len; ++i) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') 
                    dp[i] = (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
            }
            ans = ans > dp[i] ? ans : dp[i];
        }

        return ans;*/

        // 栈
        /*
        int s_len = s.length(), ans = 0;
        if (s_len < 2) return 0;
        stack<int> stk;
        stk.push(-1);

        for (int i = 0; i < s_len; ++i) {
            if (s[i] == '(') stk.push(i);
            else {
                stk.pop();
                if (stk.empty()) stk.push(i);
                else ans = ans > i - stk.top() ? ans : i - stk.top();
            }
        }

        return ans;*/

        // 正向逆向结合
        int s_len = s.length();
        if (s_len < 2) return 0;
        int ans = 0, left = 0, right = 0;

        for (int i = 0; i < s_len; ++i) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) ans = ans > 2 * left ? ans : 2 * left;
            else if (right > left) left = right = 0;
        }

        left = right = 0;

        for (int i = s_len - 1; i >= 0; --i) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) ans = ans > 2 * left ? ans : 2 * left;
            else if (left > right) left = right = 0;
        }

        return ans;
    }
};
// @lc code=end

