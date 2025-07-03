class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        while (true) {
            auto it = find(nums.begin(), nums.end(), val);  // 查找 val
            if (it != nums.end()) {
                nums.erase(it);  // 删除找到的 val
            } else {
                break;  // 没有找到 val，跳出循环
            }
        }
        return nums.size();  // 返回剩余数组的长度
    }
};