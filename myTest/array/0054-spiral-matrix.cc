/* [力扣题目链接](https://leetcode.cn/problems/spiral-matrix/)

给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

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
        // 请在此处实现你的代码
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Test Case 1: matrix = [[1,2,3],[4,5,6],[7,8,9]]" << endl;
    vector<int> res1 = sol.spiralOrder(matrix1);
    cout << "Result: ";
    for (int x : res1) cout << x << " ";
    cout << endl << "Expected: 1 2 3 6 9 8 7 4 5" << endl;
    cout << "----------------" << endl;

    return 0;
}