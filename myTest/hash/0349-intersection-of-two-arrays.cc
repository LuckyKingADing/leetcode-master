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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // // 1.如果不限制大小，那么就不能用数组了，就得用unordered_set存储
        // unordered_set<int> result_set; // 存放结果，之所以用set是为了给结果集去重
        // unordered_set<int> nums_set(nums1.begin(), nums1.end());

        // for (int num : nums2) {
        //     if (nums_set.find(num) != nums_set.end()) {
        //         result_set.insert(num);
        //     }
        // }

        // return vector<int>(result_set.begin(), result_set.end());

        // 2.如果限制了大小和数值范围：可以使用数组
        /* 本题后面 力扣改了 题目描述 和 后台测试数据，增添了 数值范围： 
            * 1 <= nums1.length, nums2.length <= 1000
            * 0 <= nums1[i], nums2[i] <= 1000
            所以就可以 使用数组来做哈希表了， 因为数组都是 1000以内的。  */
        unordered_set<int> result_set;
        int hash[1005] = {0};
        for (int num : nums1) {
            hash[num] = 1; // 初始化num1中的都为1，存储在hash中，同时进行了降重操作
        }
        for (int num : nums2) {
            if (hash[num] == 1) { // 等于1才存储，有交集
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());

    }
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