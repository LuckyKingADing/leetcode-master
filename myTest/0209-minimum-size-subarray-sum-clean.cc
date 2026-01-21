#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 二刷
        // 滑动窗口法
        /* 自己的思路：
           PS:还是没想起来 看了之前的解析，还有一种暴力解法，之后刷力扣再在官网做吧。
        */
        int start = 0;
        int length = 0; // 输出的最小长度
        int n = nums.size();
        int result = INT_MAX;//最大值
        int sum = 0; // 加和
        for (int end = 0; end < n; end++) {
           sum += nums[end];

           while (sum >= target) {
                length = end - start + 1;
                result = min(result, length);
                sum -= nums[start];
                start++;
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