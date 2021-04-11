/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-04-10 20:22:37
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-04-11 19:54:09
 */
/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (56.38%)
 * Likes:    1241
 * Dislikes: 0
 * Total Accepted:    249.7K
 * Total Submissions: 442.9K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：digits = "23"
 * 输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：digits = ""
 * 输出：[]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：digits = "2"
 * 输出：["a","b","c"]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * digits[i] 是范围 ['2', '9'] 的一个数字。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // 递归
    /*
    void dfs(string digits, vector<vector<string>> symbols, int count, int length, vector<string>& ans, string tmp) {
            if (count == length)
                ans.push_back(tmp);
            else {
                int digit = int(digits[count] - '0');
                for(int i = 0; i < symbols[digit - 2].size(); ++i)
                    dfs(digits, symbols, count + 1, length, ans, tmp+symbols[digit - 2][i]);
            }
    }*/


    vector<string> letterCombinations(string digits) {
        // 暴力
        /*
        vector<vector<string>> symbols = { 
            {"a", "b", "c"}, 
            {"d", "e", "f"}, 
            {"g", "h", "i"}, 
            {"j", "k", "l"}, 
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
        };
        vector<string> ans;
        int len = digits.size();
        int digit1, digit21, digit22, digit31, digit32, digit33, digit41, digit42, digit43, digit44;

        switch(len){
            case 0: return ans;
            case 1:
                digit1 = int(digits[0] - '0');
                return symbols[digit1 - 2];
            case 2:
                digit21 = int(digits[0] - '0');
                digit22 = int(digits[1] - '0');
                for (int i = 0; i < symbols[digit21 - 2].size(); ++i)
                    for (int j = 0; j < symbols[digit22 - 2].size(); ++j)
                        ans.push_back(symbols[digit21 - 2][i] + symbols[digit22 - 2][j]);
                break;
            case 3:
                digit31 = int(digits[0] - '0');
                digit32 = int(digits[1] - '0');
                digit33 = int(digits[2] - '0');
                for (int i = 0; i < symbols[digit31 - 2].size(); ++i)
                    for (int j = 0; j < symbols[digit32 - 2].size(); ++j)
                        for (int k = 0; k < symbols[digit33 - 2].size(); ++k)
                            ans.push_back(symbols[digit31 - 2][i] + symbols[digit32 - 2][j] + symbols[digit33 - 2][k]);
                break;
            case 4:
                digit41 = int(digits[0] - '0');
                digit42 = int(digits[1] - '0');
                digit43 = int(digits[2] - '0');
                digit44 = int(digits[3] - '0');
                for (int i = 0; i < symbols[digit41 - 2].size(); ++i)
                    for (int j = 0; j < symbols[digit42 - 2].size(); ++j)
                        for (int k = 0; k < symbols[digit43 - 2].size(); ++k)
                            for (int l = 0; l < symbols[digit44 - 2].size(); ++l)
                                ans.push_back(symbols[digit41 - 2][i] + symbols[digit42 - 2][j] + symbols[digit43 - 2][k] + symbols[digit44 - 2][l]);
                break;
        }

        return ans;*/

        // 递归
        /*
        vector<vector<string>> symbols = { 
            {"a", "b", "c"}, 
            {"d", "e", "f"}, 
            {"g", "h", "i"}, 
            {"j", "k", "l"}, 
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
        };
        vector<string> ans;
        string tmp;
        int len = digits.size();
        if (len == 0) return ans;
        
        dfs(digits, symbols, 0, len, ans, tmp);

        return ans;*/

        // 回溯
        vector<string> combinations;
        if (digits.empty()) return combinations;
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string combination;

        backtrack(combinations, phoneMap, digits, 0, combination);

        return combinations;
    }

    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length()) combinations.push_back(combination);
        else {
            char digit = digits[index];
            const string& letters = phoneMap.at(digit);
            for (const char& letter:letters) {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};
// @lc code=end

