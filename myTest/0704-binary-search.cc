/* 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:        
输入: nums = [-1,0,3,5,9,12], target = 9     
输出: 4       
解释: 9 出现在 nums 中并且下标为 4     

示例 2:    
输入: nums = [-1,0,3,5,9,12], target = 2     
输出: -1        
解释: 2 不存在 nums 中因此返回 -1        

提示：    
* 你可以假设 nums 中的所有元素是不重复的。
* n 将在 [1, 10000]之间。
* nums 的每个元素都将在 [-9999, 9999]之间。 */

#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
    // 1.暴力解法
    // 草稿：nums target 输出index
    //    int size = nums.size();
    //    for (int i = 0; i < size; i++) {
    //         if (target == nums[i]) {
    //             return i;
    //         }
    //    }
    //    return -1;  
    // }
    // PS：暴力解法的缺陷：在数据量太大的情况下，逐个遍历非常费时

    // 2.二分查找：关键点：有序数组
    // 左闭右闭
    int left = 0;
    int right = (int)nums.size() - 1; // 如果nums为空，这里right赋值可能会有问题，可以显：int right = (int)nums.size() - 1; 显式转为有符号数，或者先定义 int n = nums.size();。

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (nums[middle] > target) {
            right = middle - 1;
        } else if (nums[middle] < target) {
            left = middle + 1;
        } else {
            return middle;
        }
    }
    return -1;
    }
};

int main () {
    Solution sol;
    
    // 示例 1
    std::vector<int> nums1 = {-1,0,3,5,9,12};
    int target1 = 9;
    std::cout << "Test Case 1: target = 9, Result = " << sol.search(nums1, target1) << " (Expected: 4)" << std::endl;

    // 示例 2: 目标值不存在
    int target2 = 2;
    std::cout << "Test Case 2: target = 2, Result = " << sol.search(nums1, target2) << " (Expected: -1)" << std::endl;

    // 示例 3: 边界情况
    std::vector<int> nums3 = {5};
    int target3 = 5;
    std::cout << "Test Case 3: target = 5, Result = " << sol.search(nums3, target3) << " (Expected: 0)" << std::endl;

    return 0;
}
