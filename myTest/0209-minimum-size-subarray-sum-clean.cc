#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 请在此处实现你的代码
        
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