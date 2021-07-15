/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (44.79%)
 * Likes:    664
 * Dislikes: 0
 * Total Accepted:    150.3K
 * Total Submissions: 335.6K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // my solution
    /*string addString(string num1, string num2) {
        int idx1 = num1.size() - 1, idx2 = num2.size() - 1;
        int carry = 0;
        string ans = "";
        char ch;

        while (idx1 >= 0 && idx2 >= 0) {
            int tmp = num1[idx1] - '0' + num2[idx2] - '0' + carry;
            carry = 0;
            if (tmp >= 10) {
                tmp -= 10;
                carry = 1;
            }
            ch = tmp + '0';
            ans.insert(0, 1, ch);
            idx1--;
            idx2--;
        }

        if (carry > 0) {
            if (idx1 < 0 && idx2 < 0) ans.insert(0, 1, '1');
            else if (idx1 >= 0) {
                while (idx1 >= 0) {
                    int tmp = num1[idx1] - '0' + carry;
                    carry = 0;
                    if (tmp == 10) {
                        tmp = 0;
                        carry = 1;
                    }
                    ch = tmp + '0';
                    ans.insert(0, 1, ch);
                    idx1--;
                }
                if (carry > 0) ans.insert(0, 1, '1');
            }
            else {
                while (idx2 >= 0) {
                    int tmp = num2[idx2] - '0' + carry;
                    carry = 0;
                    if (tmp == 10) {
                        tmp = 0;
                        carry = 1;
                    }
                    ch = tmp + '0';
                    ans.insert(0, 1, ch);
                    idx2--;
                }
                if (carry > 0) ans.insert(0, 1, '1');
            }
        }

        else if (idx1 >= 0) ans = num1.substr(0, idx1 + 1) + ans;
        else if (idx2 >= 0) ans = num2.substr(0, idx2 + 1) + ans;

        return ans;
    }*/


    string multiply(string num1, string num2) {
        // my solution
        /*string ans = "0";
        if (num1[0] == '0' || num2[0] == '0') return ans;

        for (int i = 0; i < num2.length(); ++i) {
            int mul_Num = num2[i] - '0';
            if (mul_Num == 0) continue;
            string tmp = num1;

            for (int i = 0; i < mul_Num - 1; ++i) tmp = addString(tmp, num1);
            tmp.append(num2.length() - i - 1, '0');
            ans = addString(ans, tmp); 
        }

        return ans;*/

        // 做乘法
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.length(), n = num2.length();
        vector<int> ans(m + n, 0);
        for (int i = m - 1; i >= 0; --i) {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; --j) {
                int y = num2[j] - '0';
                ans[i + j + 1] += x * y;
            }
        }

        for (int i = m + n - 1; i > 0; --i) {
            ans[i - 1] += ans[i] / 10;
            ans[i] %= 10;
        }

        string ansStr;
        int index = ans[0] == 0 ? 1 : 0;
        while (index < m + n) {
            ansStr.push_back(ans[index] + '0');
            index++;
        }

        return ansStr;
    }
};
// @lc code=end

