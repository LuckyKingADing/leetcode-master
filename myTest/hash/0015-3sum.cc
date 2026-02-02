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
    vector<vector<int>> threeSum(vector<int>& nums);
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

    return 0;
}