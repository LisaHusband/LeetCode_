class Solution {
public:
    void backtrack(int start, int target, std::vector<int>& candidates, std::vector<int>& current_combination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current_combination);  // 找到有效组合，加入结果
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) {  // 剪枝
                continue;
            }
            current_combination.push_back(candidates[i]);  // 选择当前数字
            backtrack(i, target - candidates[i], candidates, current_combination, result);  // 递归继续搜索
            current_combination.pop_back();  // 回溯，撤销选择
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_combination;
        backtrack(0, target, candidates, current_combination, result);
        return result;
    }
};