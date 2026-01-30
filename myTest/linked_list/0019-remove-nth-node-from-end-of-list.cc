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

        // 自己看了思路，自己尝试一下
        // 快慢节点；虚拟头节点，slow指向要删除的上一个节点
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* fast = dummyHead; // fast要比slow快n+1；怎么做到？
        ListNode* slow = dummyHead;

        // 代码随想录的想法
        // while((n + 1) && fast != NULL) { // 要加一个判断条件fast != NULL
        //     fast = fast->next;
        //     n--;
        // }

        // while(fast != NULL) {
        //     fast = fast->next;
        //     slow = slow->next;
        // } // 结束的时候，fast在null，slow在要删除的节点的上一个


        // 结合ai进行优化代码逻辑，更安全：
        // 先让fast走n步，顺道判断一下是否n大于链表长度，如果大于，则返回head;
        for(int i = 0; i < n; i++) { // 走n步，走n步也可以，这时候n走到结尾就可以，下面的和slow一起走的操作，就是判断fast->next是否为null

            if (fast->next == nullptr) { //说明还没让fast 走完n步，就咔嚓结束了，n大于链表长度；这里判断不可以写成fast==nullptr
                delete dummyHead;
                return head;
            }
            fast = fast->next;

        }

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // 让slow->next = slow ->next->next; tmp=slow->next,delete tmp;
        ListNode* tmp = slow->next; //要删除
        slow->next = slow->next->next;
        delete tmp;
        
        ListNode* resultHead = dummyHead->next;
        delete dummyHead;
        return resultHead;
        
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