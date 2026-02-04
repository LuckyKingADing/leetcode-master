/* [力扣题目链接](https://leetcode.cn/problems/two-sum/)

给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target 的那两个整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]

提示：
* 2 <= nums.length <= 10^4
* -10^9 <= nums[i] <= 10^9
* -10^9 <= target <= 10^9
* 只会存在一个有效答案

进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map; // 先是元素 后是下标
        for (int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，在map中寻找是否有匹配的key
            // 如果找到，iter 指向该元素；否则，iter == map.end()
            // iter 得到的是 unordered_map 中找到的键值对（pair）。         
            // iter->first 是键（元素值），iter->second 是值（下标）。
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) { // 找到了
                // iter->second是之前元素的下标；i是当前元素下标
                return {iter->second, i}; // 返回数组：{}
            }           
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中：pair<int, int>(i,j)
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = sol.twoSum(nums1, target1);
    cout << "Test Case 1: nums=[2,7,11,15], target=9, Result = [" << result1[0] << "," << result1[1] << "] (Expected: [0,1])" << endl;

    // 测试用例 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = sol.twoSum(nums2, target2);
    cout << "Test Case 2: nums=[3,2,4], target=6, Result = [" << result2[0] << "," << result2[1] << "] (Expected: [1,2])" << endl;

    // 测试用例 3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = sol.twoSum(nums3, target3);
    cout << "Test Case 3: nums=[3,3], target=6, Result = [" << result3[0] << "," << result3[1] << "] (Expected: [0,1])" << endl;

    return 0;
}