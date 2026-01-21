#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

/*
返回的是数量。


关键：可以从任意一棵树开始采摘，
你有两个篮子，每个篮子只能装一种水果。换句话说，在你连续摘的那段树上，最多只能出现两种不同的水果。一旦遇到第三种水果，你必须停止（不能“把第三种放进已有两个篮子里”）
举例 2 — nums = [1,2,3,2,2]
从索引 0 开始：能摘到 [1,2] → 长度 2（碰到第三种 3 就停）。
从索引 1 开始：能摘到 [2,3,2,2] → 只包含 {2,3}，长度 4（最优）。
从索引 2 开始：能摘到 [3,2,2] → 长度 3 

示例 1：
输入：fruits = [1,2,1]
输出：3   从索引0开始

示例 2：
输入：fruits = [0,1,2,2]
输出：3    从索引1开始 

示例 3：
输入：fruits = [1,2,3,2,2]
输出：4    从索引1开始
*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if (n <= 2) { return n; } // 各放一种就ok了，直接是两个。
        
        int left = 0;
        map<int, int> fruitCount; // 自动会初始化为0 
        int length = 0; // 记录窗口大小
        for (int right = 0; right < n; right++) {
            fruitCount[fruits[right]]++; // 当前水果加入窗口，相同类型的水果加到一起

            while (fruitCount.size() > 2) { // 只要窗口内的水果种类超过两种，就要缩小窗口
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) { // 如果这个水果种类的数量变成0,就从map中删除这个种类的水果
                    fruitCount.erase(fruits[left]);
                }
                left++; // 别忘了这里：左指针要右移，缩小窗口

            }

            length = max(length, right - left + 1); // 现在水果种类不超过2种，计算当前窗口长度，并更新最大值。
        }
        return length;
        
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
    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Test Case 2: fruits = [0, 1, 2, 2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits2) << " (Expected: 3)" << endl;
    cout << "----------------" << endl;

    // 测试用例 3
    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Test Case 3: fruits = [1, 2, 3, 2, 2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits3) << " (Expected: 4)" << endl;
    cout << "----------------" << endl;

    // 测试用例 4: 空数组
    vector<int> fruits4 = {};
    cout << "Test Case 4: fruits = []" << endl;
    cout << "Result: " << sol.totalFruit(fruits4) << " (Expected: 0)" << endl;
    cout << "----------------" << endl;

    // 测试用例 5: 全相同
    vector<int> fruits5 = {2,2,2,2};
    cout << "Test Case 5: fruits = [2,2,2,2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits5) << " (Expected: 4)" << endl;
    cout << "----------------" << endl;

    // 测试用例 6: 交替两种
    vector<int> fruits6 = {1,2,1,2,1,2};
    cout << "Test Case 6: fruits = [1,2,1,2,1,2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits6) << " (Expected: 6)" << endl;
    cout << "----------------" << endl;

    // 测试用例 7: 严格递增
    vector<int> fruits7 = {1,2,3,4,5};
    cout << "Test Case 7: fruits = [1,2,3,4,5]" << endl;
    cout << "Result: " << sol.totalFruit(fruits7) << " (Expected: 2)" << endl;
    cout << "----------------" << endl;

    // 测试用例 8: 混合复杂
    vector<int> fruits8 = {0,1,1,1,2,3,2,2};
    cout << "Test Case 8: fruits = [0,1,1,1,2,3,2,2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits8) << " (Expected: 4)" << endl;
    cout << "----------------" << endl;

    return 0;
}