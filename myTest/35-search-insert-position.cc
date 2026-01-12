/* https://leetcode.cn/problems/search-insert-position/description/
https://programmercarl.com/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.html#%E6%80%9D%E8%B7%AF


给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。
示例 1:
输入: nums = [1,3,5,6], target = 5
输出: 2

示例 2:
输入: nums = [1,3,5,6], target = 2
输出: 1

示例 3:
输入: nums = [1,3,5,6], target = 7
输出: 4

草稿：
1.
nums target，插入target按顺序排序应该在nums中的索引位置
二分 []
int left = 0;
int 

*/

#include <iostream>
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        // 1.暴力解法
        // 2.二分 []
        int left = 0;
        int right = (int)nums.size() - 1;
        
        while(left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] < target) {
                // 错误写法（傻了）：middle = left + 1;
                left = middle + 1;
            } else if (nums[middle] > target) {
                 // 错误写法（傻了）：middle = right - 1;
                 right = middle - 1;
            } else {
                return middle;
            }
        }

        // 关键！！（我漏了这一步）
        // 重点：如果循环结束没找到，left 就是插入位置
        // 比如 nums=[1,3], target=2: 
        // 1. left=0, right=1, middle=0, nums[0]<2 -> left=1
        // 2. left=1, right=1, middle=1, nums[1]>2 -> right=0
        // 3. left=1, right=0, 循环结束, 返回 left=1
        return left;
        /* PS：
        可以把 left 和 right 想象成两个不断靠拢的边界，它们在试图「夹住」目标值。

        left 始终代表：「第一个可能大于或等于 target 的位置」。
        right 始终代表：「最后一个可能小于或等于 target 的位置」。
        当循环结束时（left > right），它们刚好错位了：

        right 停在了比 target 小的最近位置。
        left 停在了比 target 大的最近位置。
        因为我们要寻找插入位置，所以应该返回那个「第一个比 target 大的元素」所在的索引，而这个索引正好就是 left。*/
    }
};

int main () {
    // 测试1：
    Solution sol;
    std::vector<int> nums = {1,3,5,6};
    int target = 5;
    int index = sol.searchInsert(nums, target);
    std::cout << "Test Case 1: target = 5, Result = " << index << " (Expected: 2)" << std::endl;
    
    // 测试2：
    target = 2; 
    index = sol.searchInsert(nums, target);
    std::cout << "Test Case 2: target = 2, Result = " << index << " (Expected: 1)" << std::endl;

    // 测试3：
    target = 7;
    index = sol.searchInsert(nums, target);
    std::cout << "Test Case 3: target = 7, Result = " << index << " (Expected: 4)" << std::endl;
    return 0;
}