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
        // 跟着打一遍：
        // 空数组判断:行列都判断一遍
        if (matrix.size() == 0 || matrix[0].size() == 0) { return {}; } // 返回空数组而不是返回0

        int rows = matrix.size(); // 行
        int columns = matrix[0].size(); // 列
        int total = rows * columns;
        vector<int> res(total); // 保存结果
        int startx = 0; // 每次循环的起始x y索引
        int starty = 0;

        int loop = min(rows, columns) / 2;//循环的次数，需要注意计算方法
        int mid = min(rows, columns) / 2; //中间位置的计算方式

        int count = 0; // res数组中的索引计数
        int offset = 1; // 每一圈循环，需要控制每一条边的遍历长度

        // ps:变量并非在一开始想好，在过程中慢慢补也可以。

        int i,j;
        
        while (loop --) {
            i = startx;
            j = starty;

            for (j = starty; j < starty + columns - offset; j++) {
                res[count++] = matrix[startx][j];
            }

            for (i = startx; i < startx +rows - offset; i++) {
                res[count++] = matrix[i][j];
            }

            for (; j > starty; j--) {
                res[count++] = matrix[i][j];
            }

            for (; i > startx; i--) {
                res[count++] = matrix[i][starty];
            }

            startx++;
            starty++;

            // offset 要加2？为什么
            offset += 2;

        }

        if (min(rows, columns) % 2) {
            if (rows > columns) { // 行大于列，中间是 一小段列
                for (int i = mid; i < mid + rows - columns + 1; i++) {
                    res[count++] = matrix[i][mid];
                }
            } else {
                for (int i = mid; i < mid + columns - rows + 1; i++) {
                    res[count++] = matrix[mid][i];
                }
            }
        }
        return res; // 返回最终的vector数组

        // ps：for循环的边界条件还真挺难判断的：有什么好的方法吗：
            // 1.推导公式
            // 2.打印cout调试输出，用于测试遍历是否正确
            // 3.严格使用左闭右开的原则，最右侧边界不包含，到了就终止
            // 4.画图模拟，
        // ps：感觉加入变量进行测试还是挺好用的，然后打印调试输出。

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