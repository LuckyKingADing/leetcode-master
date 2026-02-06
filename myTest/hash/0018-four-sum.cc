/* [力扣题目链接](https://leetcode.cn/problems/4sum/)

题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：
答案中不可以包含重复的四元组。

示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // 先排序
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝处理
            if (nums[k] > target && nums[k] >= 0) {
                break; // 使用break，统一通过最后的return返回
            }
            // 对nums[i]去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }

            for (int i = k + 1; i < nums.size(); i++) {
                // 2级剪纸处理
                if (nums[k] + nums[i] > target && nums[i] >= 0) {
                    continue;
                }
                // 对nums[i]去重
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right >left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) { right--;    
                    } // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                    else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                        left++;
                    } else {
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        // 对nums[left]和nums[right]去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案
                        right--;
                        left++;
                    } 

                }
            }
        }
        return result;
    }
};



int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;
    vector<vector<int>> result1 = sol.fourSum(nums1, target1);
    cout << "Test Case 1: nums=[1,0,-1,0,-2,2], target=0, Result = [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-1,0,0,1],[-2,-1,1,2],[-2,0,0,2]])" << endl;

    // 测试用例 2
    vector<int> nums2 = {};
    int target2 = 0;
    vector<vector<int>> result2 = sol.fourSum(nums2, target2);
    cout << "Test Case 2: nums=[], target=0, Result = [] (Expected: [])" << endl;

    // 测试用例 3
    vector<int> nums3 = {0};
    int target3 = 0;
    vector<vector<int>> result3 = sol.fourSum(nums3, target3);
    cout << "Test Case 3: nums=[0], target=0, Result = [] (Expected: [])" << endl;

    // 测试用例 4
    vector<int> nums4 = {1, -2, -5, -4, -3, 3, 3, 5};
    int target4 = -11;
    vector<vector<int>> result4 = sol.fourSum(nums4, target4);
    cout << "Test Case 4: nums=[1,-2,-5,-4,-3,3,3,5], target=-11, Result = [";
    for (size_t i = 0; i < result4.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result4[i].size(); j++) {
            cout << result4[i][j];
            if (j < result4[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result4.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-5,-4,-3,1]])" << endl;

    // 测试用例 5
    vector<int> nums5 = {2, 2, 2, 2, 2};
    int target5 = 8;
    vector<vector<int>> result5 = sol.fourSum(nums5, target5);
    cout << "Test Case 5: nums=[2,2,2,2,2], target=8, Result = [";
    for (size_t i = 0; i < result5.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result5[i].size(); j++) {
            cout << result5[i][j];
            if (j < result5[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result5.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[2,2,2,2]])" << endl;

    // 测试用例 6
    vector<int> nums6 = {-2, -1, 0, 0, 1, 2};
    int target6 = 0;
    vector<vector<int>> result6 = sol.fourSum(nums6, target6);
    cout << "Test Case 6: nums=[-2,-1,0,0,1,2], target=0, Result = [";
    for (size_t i = 0; i < result6.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result6[i].size(); j++) {
            cout << result6[i][j];
            if (j < result6[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result6.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]])" << endl;

    // 测试用例 7
    vector<int> nums7 = {1, 1, 1, 1};
    int target7 = 4;
    vector<vector<int>> result7 = sol.fourSum(nums7, target7);
    cout << "Test Case 7: nums=[1,1,1,1], target=4, Result = [";
    for (size_t i = 0; i < result7.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result7[i].size(); j++) {
            cout << result7[i][j];
            if (j < result7[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result7.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[1,1,1,1]])" << endl;

    // 测试用例 8
    vector<int> nums8 = {-1, 0, 1};
    int target8 = 0;
    vector<vector<int>> result8 = sol.fourSum(nums8, target8);
    cout << "Test Case 8: nums=[-1,0,1], target=0, Result = [] (Expected: [])" << endl;

    // 测试用例 9
    vector<int> nums9 = {0, 0, 0, 0};
    int target9 = 0;
    vector<vector<int>> result9 = sol.fourSum(nums9, target9);
    cout << "Test Case 9: nums=[0,0,0,0], target=0, Result = [";
    for (size_t i = 0; i < result9.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result9[i].size(); j++) {
            cout << result9[i][j];
            if (j < result9[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result9.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[0,0,0,0]])" << endl;

    // 测试用例 10
    vector<int> nums10 = {-5, -4, -3, -2, -1};
    int target10 = -10;
    vector<vector<int>> result10 = sol.fourSum(nums10, target10);
    cout << "Test Case 10: nums=[-5,-4,-3,-2,-1], target=-10, Result = [";
    for (size_t i = 0; i < result10.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result10[i].size(); j++) {
            cout << result10[i][j];
            if (j < result10[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result10.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-4,-3,-2,-1]])" << endl;

    return 0;
}