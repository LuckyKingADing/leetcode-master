/* [题目链接](https://kamacoder.com/problempage.php?pid=1070)

题目描述：
在一个数组中，请你计算指定区间内所有元素的和。

输入格式：
第一行包含一个整数 n，表示数组中元素的个数。
第二行包含 n 个整数，表示数组中的元素。
后续若干行，每行包含两个整数 a, b，表示查询区间 [a, b]。

输出格式：
对于每个查询，输出区间和。

示例：
输入：
5
1 2 3 4 5
0 1
1 3
输出：
3
9

*/

#include <iostream>
#include <vector>
using namespace std;

// 注意：KamaCoder 通常需要处理标准输入输出
int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    vector<int> p(n); // 前缀和数组
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        sum += nums[i];
        p[i] = sum;
    }

    int a, b;
    while (cin >> a >> b) {
        if (a == 0) cout << p[b] << endl;
        else cout << p[b] - p[a - 1] << endl;
    }

    return 0;
}