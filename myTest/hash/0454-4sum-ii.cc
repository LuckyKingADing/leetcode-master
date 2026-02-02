/* [力扣题目链接](https://leetcode.cn/problems/4sum-ii/)

给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

示例 1：
输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
输出：2
解释：
两个元组如下：
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 1, 0) -> nums1[1] + nums2[1] + nums3[1] + nums4[0] = 2 + (-1) + 2 + 0 = 0

示例 2：
输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
输出：1

提示：
* n == nums1.length
* n == nums2.length
* n == nums3.length
* n == nums4.length
* 1 <= n <= 200
* -2^28 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 2^28

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4);
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1_1 = {1, 2}, nums2_1 = {-2, -1}, nums3_1 = {-1, 2}, nums4_1 = {0, 2};
    int result1 = sol.fourSumCount(nums1_1, nums2_1, nums3_1, nums4_1);
    cout << "Test Case 1: nums1=[1,2], nums2=[-2,-1], nums3=[-1,2], nums4=[0,2], Result = " << result1 << " (Expected: 2)" << endl;

    // 测试用例 2
    vector<int> nums1_2 = {0}, nums2_2 = {0}, nums3_2 = {0}, nums4_2 = {0};
    int result2 = sol.fourSumCount(nums1_2, nums2_2, nums3_2, nums4_2);
    cout << "Test Case 2: nums1=[0], nums2=[0], nums3=[0], nums4=[0], Result = " << result2 << " (Expected: 1)" << endl;

    // 测试用例 3
    vector<int> nums1_3 = {1}, nums2_3 = {1}, nums3_3 = {1}, nums4_3 = {1};
    int result3 = sol.fourSumCount(nums1_3, nums2_3, nums3_3, nums4_3);
    cout << "Test Case 3: nums1=[1], nums2=[1], nums3=[1], nums4=[1], Result = " << result3 << " (Expected: 0)" << endl;

    return 0;
}