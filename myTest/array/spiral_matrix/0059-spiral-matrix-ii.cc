/* [力扣题目链接](https://leetcode.cn/problems/spiral-matrix-ii/)

给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]

提示：
* 1 <= n <= 20

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 一刷：先看了一遍代码随想录的答案，实例，发现考虑的东西还是很多的，看完之后再来尝试协议下思路吧：
        /* 1.坚持循环不变量，左闭右开原则 左上到右上，到右下，到左下，到左上；while循环，loop控制循环次数，循环次数loop = n /2 ，n= 3,循环一次 ，n=4，循环两次
            2.每个loop循环的终止索引：offset = 1，第一次循环终止为<n-offset，也就是第一次循环，每行n的话，且左闭右开，则只赋值n-1个，就要小于<n-offset，每次结束时，offset+1；
            3.定义起始的xy索引，起始x为0 y=0,每次循环结束，下一个各自+1    
            4.因为这样的话就是逐渐递增的，所以每次累加1就可以赋值了，count = 1，作为第一个，每次count++，然后赋值。
            5.如果n为奇数，那么就是最中间的位置，索引为mid = n/2，res[mid][mid]=n^2,否则；不处理
            PS：对于vector定义二维数组还是不太熟悉， vector<vector<int>> res(n, vector<int>(n, 0)); 这个表示的意思是
            *  vector<vector<int>> 表示这是一个二维向量：外层 vector 的每个元素本身又是一个 vector<int>（一维整数向量），相当于 “数组的数组”
            * (n, vector<int>(n, 0))：
             这是 vector 的构造函数参数，用来初始化 res：
                    第一个参数 n：表示外层 vector 的行数，也就是这个二维数组有 n 行。
                    第二个参数 vector<int>(n, 0)：表示外层 vector 的每个元素的初始值—— 这里是创建一个长度为 n、所有元素都是 0 的一维 vector<int>，也就是二维数组的 “一行”。
                            */
        
        // 很好，一刷的时候先看了以下md文档解析，然后自己再在这个文件夹内部进行思路重新解析，然后自己实现。最终成功，这种做法还是可行的，继续保持
        vector<vector<int>> res(n, vector<int>(n, 0));
        int loop = n / 2;
        int mid = n / 2;
        int startX = 0;
        int startY = 0;
        int count = 1; // 填入的数据
        int offset = 1; // 每次赋值的最大值
        while (loop--) { // 总共要循环loop 次;这里先循环再--
            // 定义开始和起始索引，每次循环都要重新变
            int i = startX;
            int j = startY;

            for (j; j < n - offset; j++){
                res[i][j] = count++;
            }

            // 此时j正好等于n-offset，也就是此循环的最右侧列索引
            for (i; i < n - offset; i++) {
                res[i][j] = count++;
            }

            for (j; j > startY; j--) {
                res[i][j] = count++;
            }

            for (i; i > startX; i--) {
                res[i][j] = count++;
            }

            startX++;
            startY++;
            offset++;
        }

        if (n % 2 == 1) {
            res[mid][mid] = n * n;
        }
        
        return res;
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    int n1 = 3;
    vector<vector<int>> result1 = sol.generateMatrix(n1);
    cout << "Test Case 1: n = 3" << endl;
    for (const auto& row : result1) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "(Expected: 1 2 3 / 8 9 4 / 7 6 5)" << endl;
    cout << "----------------" << endl;

    // 测试用例 2
    int n2 = 1;
    vector<vector<int>> result2 = sol.generateMatrix(n2);
    cout << "Test Case 2: n = 1" << endl;
    for (const auto& row : result2) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "(Expected: 1)" << endl;
    cout << "----------------" << endl;

    // 测试用例 3
    int n3 = 2;
    vector<vector<int>> result3 = sol.generateMatrix(n3);
    cout << "Test Case 3: n = 2" << endl;
    for (const auto& row : result3) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "(Expected: 1 2 / 4 3)" << endl;
    cout << "----------------" << endl;

    // 测试用例 4
    int n4 = 4;
    vector<vector<int>> result4 = sol.generateMatrix(n4);
    cout << "Test Case 4: n = 4" << endl;
    for (const auto& row : result4) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "(Expected: 1 2 3 4 / 12 13 14 5 / 11 16 15 6 / 10 9 8 7)" << endl;
    cout << "----------------" << endl;

    // 测试用例 5
    int n5 = 5;
    vector<vector<int>> result5 = sol.generateMatrix(n5);
    cout << "Test Case 5: n = 5" << endl;
    for (const auto& row : result5) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << "(Expected: 1 2 3 4 5 / 16 17 18 19 6 / 15 24 25 20 7 / 14 23 22 21 8 / 13 12 11 10 9)" << endl;
    cout << "----------------" << endl;

    return 0;
}