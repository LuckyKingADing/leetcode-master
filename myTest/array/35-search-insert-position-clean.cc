#include <iostream>
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        // 请在此处实现你的代码
        // 二分查找，（先把模板写出来，基本架构都一样的）
        /* 思路： 
            1. left right 左闭右闭  
            2. while left > right middle 
            3. if (nums[middle] >= val) { 
                righe = middle -1    
            } else if ( <) {left = middle +1    } 
            4. 如果是这个的话，middle不能直接返回，因为是排序数组。继续向左收缩 [1,3,5,5,5,5,6]
            5.return left;
        */
        int left = 0;
        int right = nums.size() - 1;
        // while (left > right) { // 错误写法 一开始就进不去
        while (left <= right) // ，左闭右闭区间 [left, right] 的二分查找循环条件确实是 while (left <= right)。 因为是左闭右闭，所以left等于right的时候也要继续
        {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target)
            {
                // right = middle + 1; // 错误 人都傻了
                right = middle - 1;
            } else {
                // left = middle - 1; // 错误 写反了 人都傻了
                left = middle + 1;
            }
            
        }
        return left; // 这是对的
        
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