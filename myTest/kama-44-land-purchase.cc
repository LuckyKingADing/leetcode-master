/* [题目链接](https://kamacoder.com/problempage.php?pid=1044)

题目描述：
在一个矩形区域内，由一排排土地组成。现在需要将其划分为两个部分，要求两个部分的土地总价值之差最小。

输入描述：
第一行包含两个整数 n, m，表示矩形的行数和列数。
接下来 n 行，每行包含 m 个整数，表示每块土地的价值。

输出描述：
输出一个整数，表示划分后的最小价值差。

示例：
输入：
3 3
1 2 3
2 1 3
1 2 3
输出：
0

*/

#include <iostream>
#include <vector>
#include <climits>
#include <numeric>
using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<int>> grid(n, vector<int>(m));
    int total_sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            total_sum += grid[i][j];
        }
    }

    int min_diff = INT_MAX;

    // 尝试横向切分
    int row_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            row_sum += grid[i][j];
        }
        min_diff = min(min_diff, abs(total_sum - 2 * row_sum));
    }

    // 尝试纵向切分
    int col_sum = 0;
    for (int j = 0; j < m - 1; j++) {
        for (int i = 0; i < n; i++) {
            col_sum += grid[i][j];
        }
        min_diff = min(min_diff, abs(total_sum - 2 * col_sum));
    }

    cout << min_diff << endl;

    return 0;
}