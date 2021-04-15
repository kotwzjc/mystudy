/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-04-15 09:28:41
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-04-15 19:46:28
 */
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // my solution
        if (s.size() % 2 != 0) return false;
        stack<char> stk;

        for (auto ch:s) {
            if (ch == '(' || ch == '[' || ch == '{') stk.push(ch);
            else {
                if (stk.empty()) return false;
                char tmp = stk.top();
                stk.pop();
                switch(ch) {
                    case ')': 
                        if (tmp != '(') return false;
                        break;
                    case ']': 
                        if (tmp != '[') return false;
                        break;
                    case '}': 
                        if (tmp != '{') return false;
                        break;
                }
            }
        }

        if (!stk.empty()) return false;
        return true;
    }
};
// @lc code=end

