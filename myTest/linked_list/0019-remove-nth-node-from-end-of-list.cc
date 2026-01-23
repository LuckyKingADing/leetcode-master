/* [力扣题目链接](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]

提示：
* 链表中结点的数目为 sz
* 1 <= sz <= 30
* 0 <= Node.val <= 100
* 1 <= n <= sz

进阶：你能尝试使用一趟扫描实现吗？

*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 请在此处实现你的代码
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    ListNode* result1 = sol.removeNthFromEnd(head1, 2);
    std::cout << "Test Case 1: n=2, Result = ";
    while (result1) {
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << "(Expected: 1 2 3 5)" << std::endl;

    // 测试用例 2: 删除头节点
    ListNode* head2 = new ListNode(1);
    ListNode* result2 = sol.removeNthFromEnd(head2, 1);
    std::cout << "Test Case 2: n=1, Result = (empty) (Expected: empty)" << std::endl;

    // 测试用例 3
    ListNode* head3 = new ListNode(1);
    head3->next = new ListNode(2);
    ListNode* result3 = sol.removeNthFromEnd(head3, 1);
    std::cout << "Test Case 3: n=1, Result = ";
    while (result3) {
        std::cout << result3->val << " ";
        result3 = result3->next;
    }
    std::cout << "(Expected: 1)" << std::endl;

    return 0;
}