/* [力扣题目链接](https://leetcode.cn/problems/find-common-characters/)

给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的字符列表（包括重复字符）。 例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

你可以按任意顺序返回答案。

示例 1：
输入：["bella","label","roller"]
输出：["e","l","l"]

示例 2：
输入：["cool","lock","cook"]
输出：["c","o"]

提示：
* 1 <= A.length <= 100
* 1 <= A[i].length <= 100
* A[i][j] 是小写字母

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A);
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<string> A1 = {"bella", "label", "roller"};
    vector<string> result1 = sol.commonChars(A1);
    cout << "Test Case 1: A=[\"bella\",\"label\",\"roller\"], Result = [";
    for (size_t i = 0; i < result1.size(); i++) {
        cout << "\"" << result1[i] << "\"";
        if (i < result1.size() - 1) cout << ",";
    }
    cout << "] (Expected: [\"e\",\"l\",\"l\"])" << endl;

    // 测试用例 2
    vector<string> A2 = {"cool", "lock", "cook"};
    vector<string> result2 = sol.commonChars(A2);
    cout << "Test Case 2: A=[\"cool\",\"lock\",\"cook\"], Result = [";
    for (size_t i = 0; i < result2.size(); i++) {
        cout << "\"" << result2[i] << "\"";
        if (i < result2.size() - 1) cout << ",";
    }
    cout << "] (Expected: [\"c\",\"o\"])" << endl;

    // 测试用例 3
    vector<string> A3 = {"abc", "def"};
    vector<string> result3 = sol.commonChars(A3);
    cout << "Test Case 3: A=[\"abc\",\"def\"], Result = [";
    for (size_t i = 0; i < result3.size(); i++) {
        cout << "\"" << result3[i] << "\"";
        if (i < result3.size() - 1) cout << ",";
    }
    cout << "] (Expected: [])" << endl;

    return 0;
}