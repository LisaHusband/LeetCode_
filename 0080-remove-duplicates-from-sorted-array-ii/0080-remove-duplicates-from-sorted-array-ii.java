class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }

        int j = 1;  // j 指向数组的第二个位置
        int count = 1;  // 统计当前元素的个数，初始为1（因为 nums[0] 一定会保留）

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;  // 遇到新元素，count 重置为 1
            }

            if (count <= 2) {
                nums[j] = nums[i];  // 将符合条件的元素放到 j 位置
                j++;  // j 向前移动
            }
        }

        return j;  // j 就是删除后数组的新长度
    }
}
