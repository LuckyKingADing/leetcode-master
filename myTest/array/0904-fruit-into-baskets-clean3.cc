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
示例 1：输入：fruits = [1,2,1] 输出：3   从索引0开始
示例 2：输入：fruits = [0,1,2,2] 输出：3    从索引1开始 
示例 3：输入：fruits = [1,2,3,2,2] 输出：4    从索引1开始*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        // map<>存储水果类型和种类
        // 只要是种类小于两种,就继续雷加数量到num中,
        // 如果种类>2,则进入while,减去最开始的那个种类的水果
        // 加个判断:如果之前最开始的水果种类的数量等于0了,就将它移除,否则就保留,
        //left++

        // 三刷,一次性书写通过,只要写出来伪代码,就很容易写出来全部代码。
        int left = 0;
        int n = fruits.size();
        map<int, int> fruitTypeNums;
        int result = 0;
        for (int right = 0; right < n; right++) {
            fruitTypeNums[fruits[right]]++;
            while (fruitTypeNums.size() > 2) {
                fruitTypeNums[fruits[left]]--;

                if (fruitTypeNums[fruits[left]] == 0) {
                    fruitTypeNums.erase(fruits[left]);
                }
                left++;
            }
            result = max(result, right - left + 1);
        }
        return result;
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