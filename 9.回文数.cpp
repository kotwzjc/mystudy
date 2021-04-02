/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-03-30 20:43:01
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-03-30 21:50:47
 */
/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (58.67%)
 * Likes:    1444
 * Dislikes: 0
 * Total Accepted:    607.5K
 * Total Submissions: 1M
 * Testcase Example:  '121'
 *
 * 给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。
 * 
 * 回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 121
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = -121
 * 输出：false
 * 解释：从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 10
 * 输出：false
 * 解释：从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：x = -101
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -2^31 
 * 
 * 
 * 
 * 
 * 进阶：你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        /*
        // my solution
        if(x < 0) return false;
        if(x == 0) return true;
        int pre = x;
        long long rev = 0;

        while(x != 0){
            int tmp = x % 10;
            rev = rev * 10 + tmp;
            x = x / 10;
        }

        if(rev == pre) return true;
        return false;
        */

       // recommend solution
       if(x < 0 || (x % 10 == 0 && x > 0)) return false;
       int rev = 0;

       while(x > rev){
           rev = rev * 10 + x % 10;
           x /= 10;
       }

       return x == rev || x == rev / 10;
    }
};
// @lc code=end

