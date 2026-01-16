/* [力扣题目链接](https://leetcode.cn/problems/fruit-into-baskets/)

你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规则：
1. 你有两个篮子，每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
2. 你可以选择任意一棵树开始采摘，你必须从每棵树（包括开始采摘的树）上 恰好摘一个水果 。采摘过程中，你不能错过任何一棵树。
3. 一旦你走到某棵树前，但水果种类不符合篮子的装载规则，你必须停止采摘。

给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

示例 1：
输入：fruits = [1,2,1]
输出：3

示例 2：
输入：fruits = [0,1,2,2]
输出：3

示例 3：
输入：fruits = [1,2,3,2,2]
输出：4

意思就是：
如果有连续的>=2种类的水果，就停止采摘，返回之前采摘的最大数量。
滑动窗口？窗口包含两个数，如果这两个数不相等，就继续滑动，如果相等，就停止
用一个数值记录之前采集的水果种类
windows = 0;
start = 0 end = 1
for (end=1; end < n; end++) {
    if (nums[end] != nums[start]) {
        start++;
        windows ++;
    } else {
        return windows ;
    }
}
    return windows ;

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2) return n;  // 如果水果树少于等于2棵，直接返回，因为最多只能有2种水果
        
        map<int, int> fruitCount;  // 用map记录当前窗口内每种水果的数量（map是基础数据结构，像字典一样）
        int left = 0;  // 左指针，窗口的开始
        int maxLen = 0;  // 记录最大窗口长度
        
        for (int right = 0; right < n; ++right) {  // 右指针从0到n-1移动
            fruitCount[fruits[right]]++;  // 把当前水果加到窗口里，计数+1
            
            // 如果窗口里的水果种类超过2种，就需要缩小窗口
            while (fruitCount.size() > 2) {  // size()是map中不同水果的种类数
                fruitCount[fruits[left]]--;  // 左指针的水果计数-1
                if (fruitCount[fruits[left]] == 0) {  // 如果这个水果的数量变成0，就从map里删掉
                    fruitCount.erase(fruits[left]);
                }
                left++;  // 左指针右移，缩小窗口
            }
            
            // 现在窗口里的水果种类不超过2种，计算当前窗口长度，并更新最大值
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;  // 返回最大长度

        // PS：有点难理解的，还得需要多做一做
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> fruits1 = {1, 2, 1};
    cout << "Test Case 1: fruits = [1, 2, 1]" << endl;
    cout << "Result: " << sol.totalFruit(fruits1) << " (Expected: 3)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<int> fruits2 = {1, 2, 3, 2, 2};
    cout << "Test Case 2: fruits = [1, 2, 3, 2, 2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits2) << " (Expected: 4)" << endl;
    cout << "----------------" << endl;

    return 0;
}