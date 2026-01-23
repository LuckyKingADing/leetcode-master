#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        // 请在此处实现你的代码
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target)
            {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1 ;
            } else {
                return mid;
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