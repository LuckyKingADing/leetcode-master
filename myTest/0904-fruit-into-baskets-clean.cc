#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // 请在此处实现你的代码
        
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

    return 0;
}