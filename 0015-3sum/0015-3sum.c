#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    // 预设最大三元组数量
    int maxSize = numsSize * (numsSize - 1) / 2;  // 假设返回的三元组最多为 numsSize*(numsSize-1)/2 个
    int** result = (int**)malloc(maxSize * sizeof(int*));  // 为三元组分配内存
    *returnColumnSizes = (int*)malloc(maxSize * sizeof(int));  // 为列大小分配内存
    
    *returnSize = 0;

    qsort(nums, numsSize, sizeof(int), compare);  // 排序数组

    // 遍历每个元素，作为三元组的第一个数
    for (int i = 0; i < numsSize; i++) {
        // 剪枝1: 如果当前nums[i]大于0，那么后面的数字必然大于0，直接结束
        if (nums[i] > 0) break;
        // 剪枝2: 跳过重复的元素
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        int target = -nums[i];
        int left = i + 1, right = numsSize - 1;

        // 在 [i+1, numsSize-1] 范围内查找符合条件的两个数
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                // 找到三元组，使用汇编指令优化数值存储
                result[*returnSize] = (int*)malloc(3 * sizeof(int));  // 为三元组分配内存
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                // 跳过重复的元素
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

