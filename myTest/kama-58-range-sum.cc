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

// ACM格式

#include <iostream>
#include <vector>
using namespace std;
int main(){
    /* 大致思路写一下：
    1.输入n，创建vector vec(n)，传入元素
    2.创建一个数组，保存前缀和？
    3.根据左右索引位置，计算中间区间的和：p[right]p - [left - 1],即可得到区间和?
    具体代码跟着打一下
    */
    int n, a, b;
    cin >> n;
    vector<int> vec(n); 
    vector<int> p(n);
    int presum = 0;
    // // 可防止溢出：使用long long 数据类型
    // vector<long long> vec(n);
    // vector<long long> p(n);
    // long long presum = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i]; // 注意是vec[i]，不是vec(i)
        presum += vec[i];
        p[i] = presum;
    }

    while (cin >> a >> b){
        int sum = 0;
        // // 可防止溢出，使用long long
        // long long sum;
        if (a == 0) {
            return p[b];
        } else {
            return p[b] - p[a - 1];
        }
        cout << sum << endl;
    }

    // 进一步优化：面对大量数据 读取 输出操作，最好用scanf 和 printf，耗时会小很多：   
    // 使用scanf printf
    // for (int i = 0; i < n; i++) {
    //     scanf("%d", &vec[i]); // 1
    //     presum += vec[i];
    //     p[i] = presum;
    // }

    // while (~scanf("%d%d", &a, &b)) { // 2
    //     int sum;
    //     if (a == 0) sum = p[b];
    //     else sum = p[b] - p[a - 1];
    //     printf("%d\n", sum); // 3
    // }

    
}