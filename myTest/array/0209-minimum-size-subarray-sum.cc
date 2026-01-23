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
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 请在此处实现你的代码（建议滑动窗口法）

        // 1. 暴力解法尝试
        // int n = nums.size();
        // //int length = 0;
        // int result = INT_MAX; // 补充：初始化为最大值，方便后面取最小值；不能用初始化result = 0,然后max(result,length)，因为代码是让求的最小长度而不是最大长度
        // int sum = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     int sum = 0; // 补充：换了起点，和一定要重置！在开头重置 而不是结尾

        //    // 错误 sum += nums[i];
        //     // 错误：for (int j = 1; j < n; j++)
        //     for (int j = i; j < n; j++)  // 子数组终点（从 i 开始，考虑单元素）
        //     {
        //         sum += nums[j];
        //         // 我写的错误写法
        //         // if (sum >= target)
        //         // {
        //         //     length++;
        //         // } else {
        //         //     continue;
        //         // }
        //         if (sum >= target) {
        //             int length = j - i + 1; // 当前子数组长度 j- i + 1
        //             result = min(result, length); // 更新最小长度
        //             break; // 既然已经满足条件，再往后加长度只会增加，直接跳出内层循环
        //         }
        //     }
        //     //错误写法：sum = 0; // 重置sum
        // }

        // // 如果 result 没动过，说明没找到，返回 0
        // return result == INT_MAX ? 0 : result;

        /* PS：我写的暴力解法的几个问题：
        1. sum 没有重置 (最严重的问题)
        在你的代码里，sum 是在循环外面定义的。
        问题：当你外层循环 i 移动到下一个起点时，sum 并没有清零。它会一直累加之前所有遍历过的数字。
        正确做法：每当外层循环 i 改变（即更换子数组起点）时，sum 必须重置为 0。
        2. length 的含义写错了
        问题：你用 length++ 来统计符合条件的次数，但这道题要求的是**“所有符合条件的子数组中，长度最短的那一个”**。
        正确做法：你需要一个变量（比如 result）初始化为一个很大的数（如 INT_MAX），每次找到 sum >= target 时，计算当前的长度 j - i + 1，并与 result 比较，保留更小的那个。
        3. 漏掉了单元素子数组
        问题：你的内层循环从 j = i + 1 开始。
        后果：如果数组里有一个数字本身就 >= target（例如 target=5, nums=[6]），你的代码会跳过它，因为它没考虑 i == j 的情况。
        
        4. ai还是聪明啊，确实能够替代程序员了
        */

        // 2. 滑动窗口的解法
        int n = nums.size();
        int sum = 0;
        int start = 0;
        int length = 0;
        int result = INT_MAX;
        for (int end = 0; end < n; end++) {
            sum += nums[end];

            while (sum >= target) {
                length = end - start + 1;
                result = min(result, length);
                // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
                sum -= nums[start++]; // 补充：要更新sum，要减去最开始的值num[start]

                // 错误： start++; // 我只更新了start
            }
        }

        return result == INT_MAX ? 0 : result;

        /* 我写的滑动窗口解法的问题：(跟代码随想录的思路是一一样的)
           只有一处：
           1.代码里有一个非常致命的逻辑漏洞，这会导致程序进入死循环或者逻辑错误：
            核心问题：忘了更新 sum
            在你的 while 循环中，你虽然让 start++（即缩小窗口的左边界），但是你没有从 sum 中减去被移出窗口的那个数。

            问题所在：如果 sum 已经大于等于 target 了，它进入 while 循环。你只是移动了 start，但 sum 的数值一点没变。那么下一次判断 while (sum >= target) 时，条件依然成立。
            后果：由于 sum 永远不会变小，这个 while 循环会没完没了地跑下去，直到 start 越界。这就是为什么你刚才运行结果的 Exit Code 是 148（通常代表超时或被系统终止）。*/
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