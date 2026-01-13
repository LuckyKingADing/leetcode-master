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

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 请在此处实现你的代码
        return 0;
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