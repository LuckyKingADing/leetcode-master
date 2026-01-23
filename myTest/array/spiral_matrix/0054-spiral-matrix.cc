/* [力扣题目链接](https://leetcode.cn/problems/spiral-matrix/)

给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]

提示：
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 10
* -100 <= matrix[i][j] <= 100

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 请在此处实现你的代码
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<vector<int>> matrix1 = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result1 = sol.spiralOrder(matrix1);
    cout << "Test Case 1: matrix = [[1,2,3],[4,5,6],[7,8,9]]" << endl;
    cout << "Result: ";
    for (int val : result1) {
        cout << val << " ";
    }
    cout << "(Expected: 1 2 3 6 9 8 7 4 5)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    vector<vector<int>> matrix2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result2 = sol.spiralOrder(matrix2);
    cout << "Test Case 2: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]" << endl;
    cout << "Result: ";
    for (int val : result2) {
        cout << val << " ";
    }
    cout << "(Expected: 1 2 3 4 8 12 11 10 9 5 6 7)" << endl;
    cout << "----------------" << endl;

    return 0;
}