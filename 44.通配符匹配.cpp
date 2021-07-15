/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (32.57%)
 * Likes:    714
 * Dislikes: 0
 * Total Accepted:    76.7K
 * Total Submissions: 235.4K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        // my solution
        /*int l1 = s.length(), l2 = p.length();
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
        dp[0][0] = true;

        for (int i = 0; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                if (i == 0) {
                    if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1];
                    else break;
                }
                else if (p[j - 1] == '*') dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else if (p[j - 1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = (s[i - 1] == p[j - 1]) && dp[i - 1][j - 1];
            }
        }

        return dp[l1][l2];*/

        // 贪心算法
        auto allStars = [](const string& str, int left, int right) {
            for (int i = left; i < right; ++i) {
                if (str[i] != '*') return false;
            }
            return true;
        };

        auto charMatch = [](char u, char v) {
            return u == v || v == '?';
        };

        while (s.size() && p.size() && p.back() != '*') {
            if (charMatch(s.back(), p.back())) {
                s.pop_back();
                p.pop_back();
            }
            else return false;
        }

        if (p.empty()) return s.empty();
        int sIndex = 0, pIndex = 0, sRecord = -1, pRecord = -1;
        while (sIndex < s.size() && pIndex < p.size()) {
            if (p[pIndex] == '*') {
                pIndex++;
                pRecord = pIndex;
                sRecord = sIndex;
            }
            else if (charMatch(s[sIndex], p[pIndex])) {
                sIndex++;
                pIndex++;
            }
            else if (sRecord != -1 && sRecord + 1 < s.size()) {
                sRecord++;
                sIndex = sRecord;
                pIndex = pRecord;
            }
            else return false;
        }

        return allStars(p, pIndex, p.size());
    }
};
// @lc code=end

