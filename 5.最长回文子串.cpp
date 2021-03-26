/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (33.56%)
 * Likes:    3409
 * Dislikes: 0
 * Total Accepted:    522.6K
 * Total Submissions: 1.6M
 * Testcase Example:  '"babad"'
 *
 * 给你一个字符串 s，找到 s 中最长的回文子串。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "babad"
 * 输出："bab"
 * 解释："aba" 同样是符合题意的答案。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = "cbbd"
 * 输出："bb"
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "a"
 * 输出："a"
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "ac"
 * 输出："a"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * s 仅由数字和英文字母（大写和/或小写）组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    /*
    // my solution
    // time limit exceeded
    bool check(string s, int start, int end){
        if(start < 0 || end >= s.size() || start > end) return false;
        if(start == end) return true;
        while(start < end)
            if(s[start++] != s[end--]) return false;
        return true;

    }*/

    // 中心扩展
    /*
    pair<int, int> expandAroundCenter(const string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return {left+1, right-1};
    }*/

    // Manacher
    int expand(const string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            --left;
            ++right;
        }
        return (right - left - 2) / 2;
    }

    string longestPalindrome(string s) {
        /*
        // my solution
        // time limit exceeded
        int len = s.size();
        int maxLen = 1;
        int start = 0;

        for(int i = 0; i < len; i++)
            for(int j = len - 1; j > i; j--)
                if((j-i+1) > maxLen && check(s, i, j)){
                    start = i;
                    maxLen = j - i + 1;
                }
        
        return s.substr(start, maxLen);
        */

       // 动态规划
       /*
       int n = s.size();
       vector<vector<int>> dp(n, vector<int>(n));
       string ans;
       for(int l = 0; l < n; l++){
           for(int i = 0; i < n-l; i++){
               int j = i + l;
               if(l == 0) dp[i][j] = 1;
               else if(l == 1) dp[i][j] = (s[i] == s[j]);
               else dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
               if(dp[i][j] && l + 1 > ans.size()) ans = s.substr(i, l+1);
           }
       }
       return ans;*/

       // 中心扩展
       /*
       int start = 0, end = 0;

       for (int i = 0; i < s.size(); ++i){
           auto [left1, right1] = expandAroundCenter(s, i, i);
           auto [left2, right2] = expandAroundCenter(s, i, i+1);
           if(right1 - left1 > end - start){
               start = left1;
               end = right1;
           }
           if(right2 - left2 > end - start){
               start = left2;
               end = right2;
           }
       }

       return s.substr(start, end - start + 1);*/

       // Manacher
       int start = 0, end = -1;
       string tmp = "#";
       for (char c:s){
           tmp += c;
           tmp += '#';
       }
       tmp += '#';
       s = tmp;

       vector<int> arm_len;
       int j = -1, right = -1;
       for (int i = 0; i < s.size(); ++i){
           int cur_arm_len;
           if(i <= right){
               int i_sym = 2 * j - i;
               int min_arm_len = min(arm_len[i_sym], right - i);
               cur_arm_len = expand(s, i - min_arm_len - 1, i + min_arm_len + 1);
           }
           else cur_arm_len = expand(s, i - 1, i + 1);
           arm_len.push_back(cur_arm_len);
           if(i + cur_arm_len > right){
               j = i;
               right = i + cur_arm_len;
           }
           if(cur_arm_len * 2 > end - start){
               start = i - cur_arm_len;
               end = i + cur_arm_len;
           }
       }

       string ans;
       for(int i = start; i <= end; i++){
           if (s[i] != '#') ans += s[i];
       }
       return ans;
    }
};
// @lc code=end

