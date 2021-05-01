/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.72%)
 * Likes:    881
 * Dislikes: 0
 * Total Accepted:    378K
 * Total Submissions: 930.6K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0
 * 开始）。如果不存在，则返回  -1 。
 * 
 * 
 * 
 * 说明：
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf()
 * 定义相符。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：haystack = "", needle = ""
 * 输出：0
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * haystack 和 needle 仅由小写英文字符组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        // my solution
        /*
        int len1 = haystack.size(), len2 = needle.size();
        if (len2 == 0 || haystack == needle) return 0;
        if (len1 == 0) return -1;
        int i = 0, j = 0, ans = 0;

        while (i < len1 && j < len2) {
            if (haystack[i] == needle[j]) {
                if (j == 0) ans = i;
                i++;
                j++;
            }
            else {
                i = ++ans;
                j = 0;
            }
        }

        if (j == len2) return ans;
        return -1;
        */

       // KMP算法
       int n = haystack.size(), m = needle.size();
       if (m == 0) return 0;
       vector<int> pi(m);

       for (int i = 1, j = 0; i < m; i++) {
           while (j > 0 && needle[i] != needle[j]) j = pi[j - 1];
           if (needle[i] == needle[j]) j++;
           pi[i] = j;
       }

       for (int i = 0, j = 0; i < n; i++) {
           while (j > 0 && haystack[i] != needle[j]) j = pi[j - 1];
           if (haystack[i] == needle[j]) j++;
           if (j == m) return i - m + 1;
       }

       return -1;
    }
};
// @lc code=end

