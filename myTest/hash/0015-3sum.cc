/* [力扣题目链接](https://leetcode.cn/problems/3sum/)

给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]

示例 2：
输入：nums = []
输出：[]

示例 3：
输入：nums = [0]
输出：[]

提示：
* 0 <= nums.length <= 3000
* -10^5 <= nums[i] <= 10^5

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return result;
            }

            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left) {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result1 = sol.threeSum(nums1);
    cout << "Test Case 1: nums=[-1,0,1,2,-1,-4], Result = [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result1[i].size(); j++) {
            cout << result1[i][j];
            if (j < result1[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-1,-1,2],[-1,0,1]])" << endl;

    // 测试用例 2
    vector<int> nums2 = {};
    vector<vector<int>> result2 = sol.threeSum(nums2);
    cout << "Test Case 2: nums=[], Result = [] (Expected: [])" << endl;

    // 测试用例 3
    vector<int> nums3 = {0};
    vector<vector<int>> result3 = sol.threeSum(nums3);
    cout << "Test Case 3: nums=[0], Result = [] (Expected: [])" << endl;

    // 测试用例 4
    vector<int> nums4 = {0, 0, 0};
    vector<vector<int>> result4 = sol.threeSum(nums4);
    cout << "Test Case 4: nums=[0,0,0], Result = [";
    for (size_t i = 0; i < result4.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result4[i].size(); j++) {
            cout << result4[i][j];
            if (j < result4[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result4.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[0,0,0]])" << endl;

    // 测试用例 5
    vector<int> nums5 = {-2, 0, 0, 2, 2};
    vector<vector<int>> result5 = sol.threeSum(nums5);
    cout << "Test Case 5: nums=[-2,0,0,2,2], Result = [";
    for (size_t i = 0; i < result5.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result5[i].size(); j++) {
            cout << result5[i][j];
            if (j < result5[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result5.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-2,0,2]])" << endl;

    // 测试用例 6
    vector<int> nums6 = {-1, -1, -1, 0, 1, 1, 1};
    vector<vector<int>> result6 = sol.threeSum(nums6);
    cout << "Test Case 6: nums=[-1,-1,-1,0,1,1,1], Result = [";
    for (size_t i = 0; i < result6.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result6[i].size(); j++) {
            cout << result6[i][j];
            if (j < result6[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result6.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-1,0,1]])" << endl;

    // 测试用例 7
    vector<int> nums7 = {1, 2, 3};
    vector<vector<int>> result7 = sol.threeSum(nums7);
    cout << "Test Case 7: nums=[1,2,3], Result = [";
    for (size_t i = 0; i < result7.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result7[i].size(); j++) {
            cout << result7[i][j];
            if (j < result7[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result7.size() - 1) cout << ",";
    }
    cout << "] (Expected: [])" << endl;

    // 测试用例 8
    vector<int> nums8 = {-4, -1, -1, 0, 1, 2};
    vector<vector<int>> result8 = sol.threeSum(nums8);
    cout << "Test Case 8: nums=[-4,-1,-1,0,1,2], Result = [";
    for (size_t i = 0; i < result8.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < result8[i].size(); j++) {
            cout << result8[i][j];
            if (j < result8[i].size() - 1) cout << ",";
        }
        cout << "]";
        if (i < result8.size() - 1) cout << ",";
    }
    cout << "] (Expected: [[-1,-1,2],[-1,0,1]])" << endl;

    return 0;
}