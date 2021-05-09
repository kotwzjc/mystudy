/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-05-02 21:41:01
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-05-09 16:50:24
 */
/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (20.42%)
 * Likes:    565
 * Dislikes: 0
 * Total Accepted:    88.7K
 * Total Submissions: 434K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) =
 * -2
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 解释: 10/3 = truncate(3.33333..) = truncate(3) = 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 解释: 7/-3 = truncate(-2.33333..) = -2
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        // my solution
        /*
        if (divisor == 1) return dividend;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        if (divisor == -1) return 0 - dividend;
        if (dividend == 0) return 0;
        if (dividend == divisor) return 1;
        if (divisor == INT_MIN) return 0;

        int ans;
        if (dividend == INT_MIN) {
            if (divisor < 0) dividend -= divisor;
            else dividend += divisor;
            ans = 1;
        }
        else ans = 0;
        int limit = pow(2, 30);

        int a_dividend = abs(dividend), a_divisor = abs(divisor);
        if (a_dividend < a_divisor) return divisor < 0 ? ans : (0 - ans);
        int ori_adivisor = a_divisor;

        while (a_dividend >= ori_adivisor) {
            int tempAns = 1;
            while (a_dividend >= a_divisor && a_divisor < limit) {
                a_divisor = a_divisor << 1;
                tempAns = tempAns << 1;
            }
            if (a_dividend >= a_divisor) {
                a_dividend -= a_divisor;
                ans += tempAns;
            }
            else {
                a_dividend -= (a_divisor >> 1);
                ans += (tempAns >> 1);
            }
            a_divisor = ori_adivisor;
        }

        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) return 0-ans;
        return ans;*/

        // 递归
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            else return -dividend;
        }
        long a = dividend;
        long b = divisor;
        int sign = 1;

        if ((a > 0 && b < 0) || (a < 0 && b > 0)) sign = -1;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;

        long res = div(a, b);
        if (sign > 0) return res > INT_MAX ? INT_MAX : res;
        else return -res;
    }


    int div(long a, long b) {
        if (a < b) return 0;
        long count = 1;
        long tb = b;

        while ((tb + tb) < a) {
            count = count + count;
            tb = tb + tb;
        }

        return count + div(a - tb, b);
    }
};
// @lc code=end

