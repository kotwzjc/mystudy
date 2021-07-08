/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (63.57%)
 * Likes:    615
 * Dislikes: 0
 * Total Accepted:    169.2K
 * Total Submissions: 266.4K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    // my solution
    /*
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& allAns, vector<int> tmpAns, int idx) {
        if (target == 0) {
            if (allAns.empty() || find(allAns.begin(), allAns.end(), tmpAns) == allAns.end())
                allAns.emplace_back(tmpAns);
            return;
        }
        if (idx == candidates.size()) return;
        if (candidates[idx] > target) return;

        dfs(candidates, target, allAns, tmpAns, idx + 1);
        tmpAns.emplace_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], allAns, tmpAns, idx + 1);
        tmpAns.pop_back();

        return;
    }*/


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // my solution
        /*vector<vector<int>> allAns;
        vector<int> tmpAns;
        sort(candidates.begin(), candidates.end());
        if (accumulate(candidates.begin(), candidates.end(), 0) < target || candidates[0] > target)
            return allAns;

        dfs(candidates, target, allAns, tmpAns, 0);
        return allAns;*/

        // backtrack
        vector<vector<int>> allAns;
        vector<int> tmpAns;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, allAns, tmpAns, 0);
        return allAns;
    }


    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& allAns, vector<int>& tmpAns, int idx) {
        if (target == 0) {
            allAns.emplace_back(tmpAns);
            return;
        }

        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] <= target) {
                tmpAns.emplace_back(candidates[i]);
                backtrack(candidates, target - candidates[i], allAns, tmpAns, i + 1);
                tmpAns.pop_back();
            }
            else break;
        }
    }
};
// @lc code=end

