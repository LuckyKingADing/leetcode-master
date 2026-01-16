

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2) { return n; }

        int left = 0;
        map<int, int>fruitCount; // 自动初始化为0
        // 错误 int fruitNum = 0;
        int length = 0; // 记录窗口大小
        for (int right = 0; right < n; right++) {
            // 错误
            // fruitNum++;
            // fruitCount[fruitNum]++;
            
            fruitCount[fruits[right]]++; // 当前水果加入窗口，相同类型的水果加到一起

            // 错误：if ((right - left + 1) > 2) 
            // 应该是如果窗口内的水果种类超过2种，就需要缩小窗口
            while (fruitCount.size() > 2) // 用while而不是if？
            {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0) { // 如果这个水果的数量变成0,就从map中删掉
                    fruitCount.erase(fruits[left]);
                }
            }

            length = max(length, right - left + 1);// 现在水果种类不超过2种，计算当前窗口长度，并更新最大值。
        }
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
    vector<int> fruits2 = {1, 2, 3, 2, 2};
    cout << "Test Case 2: fruits = [1, 2, 3, 2, 2]" << endl;
    cout << "Result: " << sol.totalFruit(fruits2) << " (Expected: 4)" << endl;
    cout << "----------------" << endl;

    return 0;
}