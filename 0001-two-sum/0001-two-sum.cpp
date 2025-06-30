class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    /**按值排序
    **/

    std::vector<std::pair<int, int>> indexed;
    for (int i = 0; i < nums.size(); ++i) {
        indexed.push_back({nums[i], i});
    }

    std::sort(indexed.begin(), indexed.end());

    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int sum = indexed[left].first + indexed[right].first;
        if (sum == target) {
            return {indexed[left].second, indexed[right].second};
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }
    
        return {};
    }
};