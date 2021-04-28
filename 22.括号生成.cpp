/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (77.07%)
 * Likes:    1728
 * Dislikes: 0
 * Total Accepted:    260.7K
 * Total Submissions: 338.1K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 3
 * 输出：["((()))","(()())","(())()","()(())","()()()"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：["()"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 回溯
    /*
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }

        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }*/

    // 按长度遍历
    shared_ptr<vector<string>> cache[100] = {nullptr};
    
    shared_ptr<vector<string>> generate(int n) {
        if (cache[n] != nullptr) return cache[n];
        if (n == 0) cache[0] = shared_ptr<vector<string>>(new vector<string>{""});
        else {
            auto result = shared_ptr<vector<string>>(new vector<string>);
            for (int i = 0; i != n; ++i) {
                auto lefts = generate(i);
                auto rights = generate(n - i - 1);
                for (const string& left : *lefts) 
                    for (const string& right : *rights)
                        result->push_back("(" + left + ")" + right);
            }
            cache[n] = result;
        }

        return cache[n];
    }


    vector<string> generateParenthesis(int n) {
        // my solution 递归
        /*
        vector<string> ans;
        if (n == 1) {
            ans.push_back("()");
        }

        else {
            for (int i = 1; i <= n / 2; ++i) {
                vector<string> tmp1 = generateParenthesis(i);
                vector<string> tmp2 = generateParenthesis(n-i);

                for (int j = 0; j < tmp1.size(); ++j) {
                    for (int k = 0; k < tmp2.size(); ++k) {
                        if (i == 1 && j == 0) ans.push_back("(" + tmp2[k] + ")");
                        string t1 = tmp1[j] + tmp2[k];
                        string t2 = tmp2[k] + tmp1[j];

                        auto it1 = find(ans.begin(), ans.end(), t1);
                        if (it1 == ans.end()) ans.push_back(t1);

                        if (t2 != t1) {
                            auto it2 = find(ans.begin(), ans.end(), t2);
                            if (it2 == ans.end()) ans.push_back(t2);
                        }
                    }
                }
            }
        }

        return ans;*/

        // 回溯
        /*
        vector<string> ans;
        string current;
        backtrack(ans, current, 0, 0, n);
        return ans;*/

        // 按长度遍历
        return *generate(n);
    }
};
// @lc code=end

