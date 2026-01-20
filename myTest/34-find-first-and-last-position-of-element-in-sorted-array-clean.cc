#include <iostream>
#include <vector>
using namespace std;

/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：你可以设计并实现时间复杂度为 $O(\log n)$ 的算法解决此问题吗？
因为要求时间复杂度了，所以必须要使用二分查找，暴力查找是n^2的时间复杂度，因此不满足条件。

示例 1：
    输入：nums = [5,7,7,8,8,10], target = 8
    输出：[3,4]

示例 2：
    输入：nums = [5,7,7,8,8,10], target = 6
    输出：[-1,-1]

示例 3：
    输入：nums = [], target = 0
    输出：[-1,-1] */

class Solution {
public:
    vector<int> findFirstAndLastPositionOfElementInSortedArray(vector<int>& nums, int target) {
        // 请在此处实现你的代码
        if (nums.size() == 0)
        {
            return {-1, -1};
        }
        
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);


        return {leftBorder, rightBorder};
        
    }

    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) 
            {
                right = mid - 1;
            } else if(nums[mid] < target) { 
                left = mid + 1;
            } else {
                // 补充
                leftBorder = mid; // 应该是等于mid
                right = mid - 1; // 并且应该继续向左收缩，看看左侧还有没有，继续找可能的第一个位置。
            }
            
        }
    
        return leftBorder;
        
        
    }

    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] < target)
            {
                left = mid + 1;
               
            } else if(nums[mid] > target) { 
                right = mid - 1; 
            } else {
                rightBorder = mid; // 等于mid才对，而不是right
                left = mid + 1; // 继续向右找右边界
            }
            
        }
        return rightBorder;
    }

    // 方案一：上面：找左右边界 然后各自返回
    // 方案二：stl模板：
        // 需要包含头文件：#include <algorithm>
    // vector<int> findFirstAndLastPositionOfElementInSortedArray(vector<int>& nums, int target) {
    // auto lo = lower_bound(nums.begin(), nums.end(), target);
    // if (lo == nums.end() || *lo != target) return {-1, -1};
    // auto hi = upper_bound(nums.begin(), nums.end(), target);
    // return {int(lo - nums.begin()), int(hi - nums.begin() - 1)};
    // }
};

int main() {
    Solution sol;
    
    // 测试用例 1
    vector<int> nums1 = {5, 7, 7, 8, 8, 10};
    int target1 = 8;
    vector<int> res1 = sol.findFirstAndLastPositionOfElementInSortedArray(nums1, target1);
    cout << "Test Case 1: [5,7,7,8,8,10], target = 8, Result = [" << res1[0] << ", " << res1[1] << "] (Expected: [3, 4])" << endl;

    // 测试用例 2
    int target2 = 6;
    vector<int> res2 = sol.findFirstAndLastPositionOfElementInSortedArray(nums1, target2);
    cout << "Test Case 2: [5,7,7,8,8,10], target = 6, Result = [" << res2[0] << ", " << res2[1] << "] (Expected: [-1, -1])" << endl;

    // 测试用例 3: 空数组
    vector<int> nums3 = {};
    int target3 = 0;
    vector<int> res3 = sol.findFirstAndLastPositionOfElementInSortedArray(nums3, target3);
    cout << "Test Case 3: [], target = 0, Result = [" << res3[0] << ", " << res3[1] << "] (Expected: [-1, -1])" << endl;

    return 0;
}