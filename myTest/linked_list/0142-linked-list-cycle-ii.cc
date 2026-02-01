/* [力扣题目链接](https://leetcode.cn/problems/linked-list-cycle-ii/)

给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

说明：不允许修改给定的链表。

示例 1：
输入：head = [3,2,0,-4], pos = 1
输出：tail connects to node index 1
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：
输入：head = [1,2], pos = 0
输出：tail connects to node index 0
解释：链表中有一个环，其尾部连接到第一个节点。

示例 3：
输入：head = [1], pos = -1
输出：no cycle
解释：链表中没有环。

提示：
* 链表中节点的数目范围是 [0, 10^4]
* -10^5 <= Node.val <= 10^5
* pos 为 -1 或者链表中的一个 有效索引

进阶：你是否可以不用额外空间解决此题？

*/

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 双指针
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            // // 快慢指针相遇，此时从head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 这个就是环的入口，返回
            }
        }
        return NULL; // 没找到则返回NULL

        // ps：代码写出来确实没有多难，因为思路更难，很难想，确实算法题更多的是数学思维啊，就跟做数学题一样，其实完全可以列草稿纸把它当成数学题来做，思路一出来之后，代码实现部分其实也没有多难，熟不熟练罢了。
        
        
    }
};

int main() {
    Solution sol;

    // 测试用例 1: 有环
    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next;  // 环到第二个节点

    ListNode* result1 = sol.detectCycle(head1);
    if (result1) {
        std::cout << "Test Case 1: Cycle detected at node with val " << result1->val << " (Expected: 2)" << std::endl;
    } else {
        std::cout << "Test Case 1: No cycle (Expected: 2)" << std::endl;
    }

    // 测试用例 2: 无环
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    ListNode* result2 = sol.detectCycle(head2);
    if (result2) {
        std::cout << "Test Case 2: Cycle detected at node with val " << result2->val << " (Expected: No cycle)" << std::endl;
    } else {
        std::cout << "Test Case 2: No cycle (Expected: No cycle)" << std::endl;
    }

    // 测试用例 3: 单个节点无环
    ListNode* head3 = new ListNode(1);

    ListNode* result3 = sol.detectCycle(head3);
    if (result3) {
        std::cout << "Test Case 3: Cycle detected at node with val " << result3->val << " (Expected: No cycle)" << std::endl;
    } else {
        std::cout << "Test Case 3: No cycle (Expected: No cycle)" << std::endl;
    }

    return 0;
}