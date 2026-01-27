/* [力扣题目链接](https://leetcode.cn/problems/remove-linked-list-elements/)

给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]

示例 2：
输入：head = [], val = 1
输出：[]

示例 3：
输入：head = [7,7,7,7], val = 7
输出：[]

提示：
* 列表中的节点数目在范围 [0, 10^4] 内
* 1 <= Node.val <= 50
* 0 <= val <= 50

*/

#include <iostream>

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// 手打一遍链表定义
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(0), next(next) {}
};


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 1.直接使用原来的链表来进行移除节点操作
        // // 需要分别处理头和非头节点
        // // 删除头节点：如果要删除的值等于
        // while (head != NULL && head->val == val) { // 注意不是if，因为可能从头节点开始连续多个节点都是要删除的
        //     ListNode* tmp = head;
        //     head = head->next; // 让头节点等于下一个链表节点
        //     delete tmp; 
        // }

        // // 删除非头节点
        // ListNode* cur = head;
        // while (cur != NULL && cur->next != NULL) { // 当前指针不是空指针，并且下一指针也非空指针
        //     if (cur->next->val == val) { // 
        //         ListNode* tmp = cur->next;
        //         cur->next = cur->next->next;
        //         delete tmp;
        //     } else {
        //         cur = cur->next; //
        //     }
        // }

        // // 返回一个链表，返回头head就可以了
        // return head;

        // 2.设置一个虚拟头节点
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头节点，传入val=0
        dummyHead->next = head; // 虚拟头节点指向head，方便后续做删除操作
        ListNode* cur = dummyHead; // 将当前的节点从虚拟头开始进行
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp; // 删除释放内存
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next; 
        delete dummyHead; // 记得要删除释放内存
        return head;
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    // 创建链表: [1,2,6,3,4,5,6]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(6);
    head1->next->next->next = new ListNode(3);
    head1->next->next->next->next = new ListNode(4);
    head1->next->next->next->next->next = new ListNode(5);
    head1->next->next->next->next->next->next = new ListNode(6);
    int val1 = 6;
    ListNode* result1 = sol.removeElements(head1, val1);
    std::cout << "Test Case 1: val = 6, Result = ";
    while (result1) { // 只要不指向最后一个空节点，就while继续
        std::cout << result1->val << " ";
        result1 = result1->next;
    }
    std::cout << "(Expected: 1 2 3 4 5)" << std::endl;

    // 测试用例 2: 空链表
    ListNode* head2 = nullptr;
    int val2 = 1;
    ListNode* result2 = sol.removeElements(head2, val2);
    std::cout << "Test Case 2: val = 1, Result = (empty) (Expected: empty)" << std::endl;

    // 测试用例 3: 全是val
    ListNode* head3 = new ListNode(7);
    head3->next = new ListNode(7);
    head3->next->next = new ListNode(7);
    head3->next->next->next = new ListNode(7);
    int val3 = 7;
    ListNode* result3 = sol.removeElements(head3, val3);
    std::cout << "Test Case 3: val = 7, Result = (empty) (Expected: empty)" << std::endl;

    // 测试用例 4: 删除不存在的值
    ListNode* head4 = new ListNode(1);
    head4->next = new ListNode(2);
    head4->next->next = new ListNode(3);
    int val4 = 4;
    ListNode* result4 = sol.removeElements(head4, val4);
    std::cout << "Test Case 4: val = 4, Result = ";
    while (result4) {
        std::cout << result4->val << " ";
        result4 = result4->next;
    }
    std::cout << "(Expected: 1 2 3)" << std::endl;

    // 测试用例 5: 删除中间的元素
    ListNode* head5 = new ListNode(1);
    head5->next = new ListNode(2);
    head5->next->next = new ListNode(3);
    head5->next->next->next = new ListNode(2);
    head5->next->next->next->next = new ListNode(4);
    int val5 = 2;
    ListNode* result5 = sol.removeElements(head5, val5);
    std::cout << "Test Case 5: val = 2, Result = ";
    while (result5) {
        std::cout << result5->val << " ";
        result5 = result5->next;
    }
    std::cout << "(Expected: 1 3 4)" << std::endl;

    // 测试用例 6: 删除头节点
    ListNode* head6 = new ListNode(2);
    head6->next = new ListNode(2);
    head6->next->next = new ListNode(3);
    int val6 = 2;
    ListNode* result6 = sol.removeElements(head6, val6);
    std::cout << "Test Case 6: val = 2, Result = ";
    while (result6) {
        std::cout << result6->val << " ";
        result6 = result6->next;
    }
    std::cout << "(Expected: 3)" << std::endl;

    // 测试用例 7: 删除尾节点
    ListNode* head7 = new ListNode(1);
    head7->next = new ListNode(2);
    head7->next->next = new ListNode(3);
    head7->next->next->next = new ListNode(2);
    int val7 = 2;
    ListNode* result7 = sol.removeElements(head7, val7);
    std::cout << "Test Case 7: val = 2, Result = ";
    while (result7) {
        std::cout << result7->val << " ";
        result7 = result7->next;
    }
    std::cout << "(Expected: 1 3)" << std::endl;

    // 测试用例 8: 只有一个节点且匹配
    ListNode* head8 = new ListNode(5);
    int val8 = 5;
    ListNode* result8 = sol.removeElements(head8, val8);
    std::cout << "Test Case 8: val = 5, Result = (empty) (Expected: empty)" << std::endl;

    // 测试用例 9: 只有一个节点且不匹配
    ListNode* head9 = new ListNode(5);
    int val9 = 6;
    ListNode* result9 = sol.removeElements(head9, val9);
    std::cout << "Test Case 9: val = 6, Result = ";
    while (result9) {
        std::cout << result9->val << " ";
        result9 = result9->next;
    }
    std::cout << "(Expected: 5)" << std::endl;

    // 测试用例 10: 多个连续的val
    ListNode* head10 = new ListNode(1);
    head10->next = new ListNode(2);
    head10->next->next = new ListNode(2);
    head10->next->next->next = new ListNode(2);
    head10->next->next->next->next = new ListNode(3);
    int val10 = 2;
    ListNode* result10 = sol.removeElements(head10, val10);
    std::cout << "Test Case 10: val = 2, Result = ";
    while (result10) {
        std::cout << result10->val << " ";
        result10 = result10->next;
    }
    std::cout << "(Expected: 1 3)" << std::endl;

    return 0;
}