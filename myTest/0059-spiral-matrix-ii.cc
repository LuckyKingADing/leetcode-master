/* [力扣题目链接](https://leetcode.cn/problems/spiral-matrix-ii/)

给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 请在此处实现你的代码
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    int n1 = 3;
    cout << "Test Case 1: n = 3" << endl;
    vector<vector<int>> res1 = sol.generateMatrix(n1);
    cout << "Result:" << endl;
    for (const auto& row : res1) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    cout << "Expected:" << endl << "1 2 3" << endl << "8 9 4" << endl << "7 6 5" << endl;
    cout << "----------------" << endl;

    return 0;
}