/* [力扣题目链接](https://leetcode.cn/problems/squares-of-a-sorted-array/)

给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
输入：nums = [-4,-1,0,3,10]
输出：[0,1,9,16,100]
解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

示例 2：
输入：nums = [-7,-3,2,3,11]
输出：[4,9,9,49,121]

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 请在此处实现你的代码
        // 1. 暴力解法
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     nums[i] = nums[i] * nums[i];
        // }
        // sort(nums.begin(), nums.end());
        // // 原来的错误：sort(nums);正确：sort(nums.begin(), nums.end())
        
        // return nums;

        // 2.双指针法，降低复杂度。
        // 思路：优化的思考： 题目给出的数组是有序的（非递减）。虽然平方后大的数可能会跑到前面（比如 -4 平方后变 16），但数组平方的最大值一定分布在原数组的两端（要么是最小的负数，要么是最大的正数），而最小值一定在中间。 
        // 更优思路：双指针法 O(n)。既然最大的数一定在两端，我们可以使用两个指针 i 和 j 分别指向起始和末尾，谁的平方大，谁就填入新结果数组的末尾，然后移动指针。
        
        int i = 0;
        int j = nums.size() - 1; 

        // 修改：
        vector<int> result(nums.size(),0); // 指定大小，初始化为0
        int n = nums.size() - 1;

        // 错误：while (i > j)
        // 正确
        while (i <= j)
        {
            if (nums[i] * nums[i] >= nums[j] * nums[j])   // 这里写大于或者大于等于都是一样的
            {
                // 错误：不能原地直接修改，会把后面还没处理到的原始值覆盖掉  nums[j] = nums[i];
                // !!!指针法的核心是需要一个额外的新数组来存放结果，因为平方后的顺序和原顺序完全对不上。

                // 原来的：
                // j--;
                // i++;

                //修改：
                result[n] = nums[i] * nums[i];
                i++;
                n--;


            } else {
                // i++;

                // 修改：
                result[n] = nums[j] * nums[j];
                j--;
                n--;

            }
            
        }
        // 记得要返回result！！！
        return result;


    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    cout << "Test Case 1: nums = [-4, -1, 0, 3, 10]" << endl;
    vector<int> res1 = sol.sortedSquares(nums1);
    cout << "Result: ";
    for (int x : res1) cout << x << " ";
    cout << "(Expected: 0 1 9 16 100)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    cout << "Test Case 2: nums = [-7, -3, 2, 3, 11]" << endl;
    vector<int> res2 = sol.sortedSquares(nums2);
    cout << "Result: ";
    for (int x : res2) cout << x << " ";
    cout << "(Expected: 4 9 9 49 121)" << endl;
    cout << "----------------" << endl;

    return 0;
}