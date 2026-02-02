/* [力扣题目链接](https://leetcode.cn/problems/intersection-of-two-arrays/)

给定两个数组，编写一个函数来计算它们的交集。

示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]

示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]

说明：
* 输出结果中的每个元素一定是唯一的。
* 我们可以不考虑输出结果的顺序。

*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2);
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1_1 = {1, 2, 2, 1}, nums2_1 = {2, 2};
    vector<int> result1 = sol.intersection(nums1_1, nums2_1);
    cout << "Test Case 1: nums1=[1,2,2,1], nums2=[2,2], Result = [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << result1[i];
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "] (Expected: [2])" << endl;

    // 测试用例 2
    vector<int> nums1_2 = {4, 9, 5}, nums2_2 = {9, 4, 9, 8, 4};
    vector<int> result2 = sol.intersection(nums1_2, nums2_2);
    cout << "Test Case 2: nums1=[4,9,5], nums2=[9,4,9,8,4], Result = [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << result2[i];
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "] (Expected: [9,4] or similar)" << endl;

    // 测试用例 3
    vector<int> nums1_3 = {1, 2, 3}, nums2_3 = {4, 5, 6};
    vector<int> result3 = sol.intersection(nums1_3, nums2_3);
    cout << "Test Case 3: nums1=[1,2,3], nums2=[4,5,6], Result = [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << result3[i];
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "] (Expected: [])" << endl;

    return 0;
}