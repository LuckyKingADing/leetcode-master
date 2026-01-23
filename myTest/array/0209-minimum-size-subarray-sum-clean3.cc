#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
/*
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
输出：0 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 三刷,终于一次性通过了
        int left = 0;
        int sum = 0;
        int n = nums.size();
        int result = INT_MAX; // 结果 从最大开始慢慢缩小
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum >= target) {
                int widSize = right - left + 1;
                result = min(result, widSize);
                sum -= nums[left];
                left++;
            }
        }
        return result == INT_MAX ? 0 : result;
        
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

    // 额外测试用例
    // 测试 3: 空数组
    vector<int> nums3 = {};
    int target3 = 5;
    cout << "Test Case 3: target = 5, nums = []" << endl;
    int res3 = sol.minSubArrayLen(target3, nums3);
    cout << "Result: " << res3 << " (Expected: 0)" << endl;
    cout << "----------------" << endl;

    // 测试 4: 单元素等于target
    vector<int> nums4 = {5};
    int target4 = 5;
    cout << "Test Case 4: target = 5, nums = [5]" << endl;
    int res4 = sol.minSubArrayLen(target4, nums4);
    cout << "Result: " << res4 << " (Expected: 1)" << endl;
    cout << "----------------" << endl;

    // 测试 5: 单元素小于target
    vector<int> nums5 = {4};
    int target5 = 5;
    cout << "Test Case 5: target = 5, nums = [4]" << endl;
    int res5 = sol.minSubArrayLen(target5, nums5);
    cout << "Result: " << res5 << " (Expected: 0)" << endl;
    cout << "----------------" << endl;

    // 测试 6: 全部元素和恰好等于target
    vector<int> nums6 = {1,1,1,1,1};
    int target6 = 5;
    cout << "Test Case 6: target = 5, nums = [1,1,1,1,1]" << endl;
    int res6 = sol.minSubArrayLen(target6, nums6);
    cout << "Result: " << res6 << " (Expected: 5)" << endl;
    cout << "----------------" << endl;

    // 测试 7: 大数测试
    vector<int> nums7 = {1000000,1000000,1000000};
    int target7 = 2000000;
    cout << "Test Case 7: target = 2000000, nums = [1000000,1000000,1000000]" << endl;
    int res7 = sol.minSubArrayLen(target7, nums7);
    cout << "Result: " << res7 << " (Expected: 2)" << endl;
    cout << "----------------" << endl;

    return 0;
}