/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (34.59%)
 * Likes:    468
 * Dislikes: 0
 * Total Accepted:    64.2K
 * Total Submissions: 185.7K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        // my solution
        /*
        vector<int> ans;
        int len_Str = s.size(), len_word = words[0].size(), num_word = words.size();
        int limit = len_Str - len_word * num_word;
        if (limit < 0) return ans;
        unordered_map<string, int> word_htable;
        int start, next, i = 0, count = 0;

        for (auto word:words) word_htable[word]++;

        while (i <= limit) {
            unordered_map<string, int> tmp_htable = word_htable;
            start = i;
            next = i + 1;
            string tmp = s.substr(i, len_word);

            while (tmp_htable[tmp] > 0) {
                tmp_htable[tmp]--;
                i += len_word;
                tmp = s.substr(i, len_word);
                count++;
            }

            if (count == num_word) ans.push_back(start);

            i = next;
            tmp_htable = word_htable;
            count = 0;
        }

        return ans;*/

        // 滑动窗口
        vector<int> ans;
        int len_Str = s.size(), len_word = words[0].size(), num_word = words.size();
        int limit = len_Str - len_word * num_word;
        if (len_Str == 0 || num_word == 0 || limit < 0) return ans;
        unordered_map<string, int> word_htable;

        for (auto word:words) word_htable[word]++;

        for (int i = 0; i < len_word; ++i) {
            int cur_cnt = 0;
            int left = i;
            int right = i;
            unordered_map<string, int> tmp_htable;

            while (right + len_word <= len_Str) {
                string tmp = s.substr(right, len_word);
                right += len_word;
                tmp_htable[tmp]++;
                cur_cnt++;

                while (tmp_htable[tmp] > word_htable[tmp]) {
                    string left_tmp = s.substr(left, len_word);
                    left += len_word;
                    tmp_htable[left_tmp]--;
                    cur_cnt--;
                }

                if (cur_cnt == num_word) ans.push_back(left);
            }
        }

        return ans;
        
    }
};
// @lc code=end

