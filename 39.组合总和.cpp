/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (72.43%)
 * Likes:    1375
 * Dislikes: 0
 * Total Accepted:    266.4K
 * Total Submissions: 367.7K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1：
 * 
 * 输入：candidates = [2,3,6,7], target = 7,
 * 所求解集为：
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2：
 * 
 * 输入：candidates = [2,3,5], target = 8,
 * 所求解集为：
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= candidates.length <= 30
 * 1 <= candidates[i] <= 200
 * candidate 中的每个元素都是独一无二的。
 * 1 <= target <= 500
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // my solution
    /*
    void Search(vector<int>& candidates, int target, int left, int right, vector<vector<int>>& ans, vector<int>& tmp) {
        if (target == 0) {
            ans.push_back(tmp);
            return;
        }
        if (left > right || candidates[left] > target) return;
        
        int num = target / candidates[left];

        for (int i = 0; i <= num; ++i){
            if (i != 0) tmp.push_back(candidates[left]);
            Search(candidates, target - candidates[left] * i, left + 1, right, ans, tmp);
        } 

        tmp.erase(tmp.end() - num, tmp.end());
        return;
    }
    */

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>&combine, int idx) {
        if (idx == candidates.size()) return;
        if (target == 0) {
            ans.emplace_back(combine);
            return;
        }

        dfs(candidates, target, ans, combine, idx+1);

        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // my solution
        /*
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        int left = 0, right = candidates.size() - 1;

        while (right >= left && candidates[right] > target) right--;
        if (right < left) return ans;

        Search(candidates, target, left, right, ans, tmp);
        return ans; 
        */

        // 搜索回溯
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};
// @lc code=end

