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
#include <cstring> // memeset函数等使用需要包含头文件
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result;
        if (A.size() == 0) return result;
        // 初始化hash，用于比较
        int hash[26] = {0};
        for (int i = 0; i < A[0].size(); i++) {
            hash[A[0][i] - 'a']++;
        }

        // 逐个遍历除第一个字符的剩余，与第一个进行比较
        int hashOtherStr[26] = {0};
        for (int i = 1; i < A.size(); i++) {
            // 清空hashOtherStr数组
            memset(hashOtherStr, 0, 26 * sizeof(int));
            for (int j = 0; j < A[i].size(); j++) {
                hashOtherStr[A[i][j] - 'a']++;
            }
            // 更新hash，最小次数
            // !!!
            for (int k = 0; k < 26; k++) {
                hash[k] = min(hash[k], hashOtherStr[k]);
            }            
        }

        // 将hash统计的字符次数，转换成输出形式
        for (int i = 0; i < 26; i++) {
            while (hash[i] != 0) { // 重复的也输出，这也是比较上面最小次数的原因，避免少输出了
                string s(1, i + 'a'); // !!! char->string
                result.push_back(s); // !!!
                hash[i]--;
            }
        }

        return result;
    }
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