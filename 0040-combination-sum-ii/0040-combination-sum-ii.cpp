class Solution {
public:
    void backtrack(int start, int target, std::vector<int>& candidates, std::vector<int>& current_combination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(current_combination);  // 找到有效组合，加入结果
            return;
        }
        
        for (int i = start; i < candidates.size(); ++i) {
            // 如果当前数字和前一个数字相同且没有跳过，就跳过当前数字，避免重复组合
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (candidates[i] > target) {  // 剪枝
                break;  // 由于候选数组已经排序，后续的数字会更大，直接结束循环
            }

            current_combination.push_back(candidates[i]);  // 选择当前数字
            backtrack(i + 1, target - candidates[i], candidates, current_combination, result);  // 递归继续搜索
            current_combination.pop_back();  // 回溯，撤销选择
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> current_combination;
        
        // 先排序，以便去重
        std::sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, current_combination, result);
        
        return result;
    }
};