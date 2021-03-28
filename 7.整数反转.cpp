/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-03-28 15:19:42
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-03-28 18:25:15
 */
/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (35.00%)
 * Likes:    2646
 * Dislikes: 0
 * Total Accepted:    630.4K
 * Total Submissions: 1.8M
 * Testcase Example:  '123'
 *
 * 给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
 * 
 * 如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。
 * 假设环境不允许存储 64 位整数（有符号或无符号）。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：x = 123
 * 输出：321
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：x = -123
 * 输出：-321
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：x = 120
 * 输出：21
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：x = 0
 * 输出：0
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
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // my solution
        /*
        if (x >= 0 && x < 10) return x;
        if(x == INT_MIN) return 0;
        int flag = x > 0 ? 1 : 0;
        x = abs(x);
        char str[32];
        
        int len = sprintf(str, "%d", x);
        char str_rev[32];
        int j = 1;
        for(int i = len - 1; i > 0; i--) str_rev[j++] = str[i];
        str_rev[j] = '\0';
        str_rev[0] = flag ? '+' : '-';

        int ans = atoi(str_rev);
        if(ans > 214748364 || ans < -214748364) return 0;
        if(ans == 214748364 && int(str[0] - 48) > 7) return 0;
        if(ans == -214748364 && int(str[0] - 48) > 8) return 0;
        ans *= 10;
        if(flag > 0) ans += int(str[0] - 48);
        else ans -= int(str[0] - 48);

        return ans;
        */

       // recommend solution
       int rev = 0;
       while(x != 0){
           int pop = x % 10;
           x /= 10;
           if(rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
           if(rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
           rev *= 10;
           rev += pop;
       }
       return rev;
    }
};
// @lc code=end

