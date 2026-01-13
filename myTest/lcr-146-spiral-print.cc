/* [力扣题目链接](https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/)

输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 其实这道题和 54. 螺旋矩阵 是一模一样的逻辑
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    cout << "Test Case: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]" << endl;
    vector<int> res = sol.spiralOrder(matrix);
    cout << "Result: ";
    for (int x : res) cout << x << " ";
    cout << endl << "Expected: 1 2 3 4 8 12 11 10 9 5 6 7" << endl;
    cout << "----------------" << endl;

    return 0;
}