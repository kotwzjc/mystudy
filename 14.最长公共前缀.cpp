/*
 * @Author: kotwzjc
 * @Github: https://github.com/kotwzjc
 * @Date: 2021-04-06 20:58:44
 * @LastEditors: kotwzjc
 * @LastEditTime: 2021-04-06 21:26:13
 */
/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.29%)
 * Likes:    1546
 * Dislikes: 0
 * Total Accepted:    488.5K
 * Total Submissions: 1.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * 0 
 * strs[i] 仅由小写英文字母组成
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // my solution
        /*
        int len = 0, flag = 1;
        string m_short, ans;

        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i].size() > len) {
                len = strs[i].size();
                m_short = strs[i];
            }
        }

        for (int i = len; i > 0; --i) {
            string tmp = m_short.substr(0, i);
            for (auto s:strs) {
                if(s.substr(0, i) != tmp) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                ans = tmp;
                break;
            }
            flag = 1;
        }

        return ans;*/

        // 横向扫描
        /*
        if (!strs.size()) return "";
        string prefix = strs[0];
        int count = strs.size();
        for (int i = 1; i < count; ++i) {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if(prefix.empty()) return "";
        }
        return prefix;*/

        // 纵向扫描
        if(!strs.size()) return "";
        int length = strs[0].size();

        for (int i = 0; i < length; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (i == strs[j].size() || strs[j][i] != c) return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }

    // 横向扫描
    /*
    string longestCommonPrefix(const string& s1, const string& s2) {
        int length = min(s1.size(), s2.size());
        int index = 0;
        while (index < length && s1[index] == s2[index]) index++;
        return s1.substr(0, index);
    }*/
};
// @lc code=end

