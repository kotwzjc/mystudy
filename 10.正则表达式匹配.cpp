/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-03-31 22:28:56
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-04-02 22:20:06
 */
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 *
 * https://leetcode-cn.com/problems/regular-expression-matching/description/
 *
 * algorithms
 * Hard (31.00%)
 * Likes:    2000
 * Dislikes: 0
 * Total Accepted:    156.6K
 * Total Submissions: 505.1K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * 
 * 
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 
 * 
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "aa" p = "a"
 * 输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入：s = "aa" p = "a*"
 * 输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "ab" p = ".*"
 * 输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：s = "aab" p = "c*a*b"
 * 输出：true
 * 解释：因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
 * 
 * 
 * 示例 5：
 * 
 * 
 * 输入：s = "mississippi" p = "mis*is*p*."
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        // my solution
        // 只想到了暴力穷举，这种方法没解出来
        /*
        int i = 0, j = 0;
        int l1 = s.length(), l2 = p.length();

        if(l1 == 0 && l2 == 0) return true;
        if(l1 != 0 && l2 == 0) return false;
        if(l1 == 0 && l2 != 0){
            if(l2 % 2 != 0) return false;
            for(int k = 1; k < l2; k += 2)
                if(p[k] != '*') return false;
            return true;
        }

        while(i < l1 && j < l2){
            if(p[j] == '.'){
                if(j + 1 < l2 && p[j + 1] == '*'){
                    j += 2;
                    if( j == l2) return true;
                    if(p[j] != '.'){
                        while(s[i] != p[j] && i + 1 < l1 && s[i+1] == s[i]) i++;
                        i++;
                    }
                }
                else{
                    j++;
                    i++;
                }
            }
            else if(p[j] >= 'a' && p[j] <= 'z'){
                if(s[i] != p[j]){
                    if(j + 1 < l2 && p[j+1] == '*')
                        j += 2;
                    else return false;
                }
                else{
                    if(j + 1 < l2 && p[j+1] == '*'){
                        int num = 1;
                        while(i + 1 < l1 && s[i+1] == s[i]){
                            i++;
                            num++;
                        }
                        i++;
                        j += 2;
                        while((i == l1 || p[j] != s[i]) && j + 1 < l2 && p[j+1] == '*') j += 2;
                        while(j < l2 && p[j] == s[i-1] && num > 0){
                            if(j + 1 < l2 && p[j+1] == '*') j += 2;
                            else{
                                j++;
                                num--;
                            }
                        }
                    }
                    else{
                        j++;
                        i++;
                        while((i == l1 || p[j] != s[i]) && j + 1 < l2 && p[j+1] == '*') j += 2;
                    }
                }
            }
        }
        if(i < l1 || j < l2) return false;

        return true;
        */

       // 动态规划
       int m = s.size();
       int n = p.size();

       auto matches = [&](int i, int j){
           if (i == 0) return false;
           if (p[j - 1] == '.') return true;
           return s[i - 1] == p[j - 1];
       };

       vector<vector<int>> f(m + 1, vector<int>(n + 1));
       f[0][0] = true;
       for(int i = 0; i <= m; ++i){
           for(int j = 1; j <= n; ++j){
               if(p[j - 1] == '*'){
                   f[i][j] |= f[i][j - 2];
                   if(matches(i, j - 1)) f[i][j] |= f[i - 1][j];
               }
               else if(matches(i, j)) f[i][j] |= f[i - 1][j - 1];
           }
       }

       return f[m][n];
    }
};
// @lc code=end

