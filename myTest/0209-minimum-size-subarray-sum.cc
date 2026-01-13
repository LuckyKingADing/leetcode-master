/* [力扣题目链接](https://leetcode.cn/problems/minimum-size-subarray-sum/)

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其 sum ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [2,3,1,2,4,3]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 请在此处实现你的代码（建议滑动窗口法）
        return 0;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    cout << "Test Case 1: target = 7, nums = [2, 3, 1, 2, 4, 3]" << endl;
    int res1 = sol.minSubArrayLen(target1, nums1);
    cout << "Result: " << res1 << " (Expected: 2)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    int target2 = 11;
    vector<int> nums2 = {1, 1, 1, 1, 1, 1, 1, 1};
    cout << "Test Case 2: target = 11, nums = [1, 1, 1, 1, 1, 1, 1, 1]" << endl;
    int res2 = sol.minSubArrayLen(target2, nums2);
    cout << "Result: " << res2 << " (Expected: 0)" << endl;
    cout << "----------------" << endl;

    return 0;
}