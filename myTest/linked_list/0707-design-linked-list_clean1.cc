/* [力扣题目链接](https://leetcode.cn/problems/design-linked-list/)

设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next 是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。

在链表类中实现这些功能：

get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。

示例：

MyLinkedList linkedList = new MyLinkedList();
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
linkedList.get(1);            //返回2
linkedList.deleteAtIndex(1);  //现在链表是1-> 3
linkedList.get(1);            //返回3

提示：
* 所有val值都在 [1, 1000] 之内。
* 操作次数将在  [1, 1000] 之内。
* 请不要使用内置的 LinkedList 库。

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

class MyLinkedList {
private: // 定义私有变量,全局变量，然后可以在构造函数中进行初始化
    ListNode* _dummyNode;
    int _size = 0;

public:
    // 使用虚拟头节点的方式进行

    // 初始化链表：构造函数
    MyLinkedList() {
        _dummyNode = new ListNode(0);
        _size = 0; // 因为这个是虚拟头节点，所以_size是为0的；
    }
    
    // 析构函数：释放内存；新增的，当程序结束之后要释放内存，释放节点
    ~MyLinkedList() {
        ListNode* cur = _dummyNode;
        while (cur != nullptr) {
            ListNode* tmp = cur;
            cur = cur->next;
            delete tmp; //一开始删除虚拟头节点，然后继续删除，直到最后一个空的，链表最后连接的空指针
        }
    }
    
    // 获取到第index个节点数值，如果index是非法数值直接返回-1， 注意index是从0开始的，第0个节点就是头结点
    int get(int index) {
        // 错误写法：if(_size < 0 || index > (_size - 1)) {return -1;}
        if(index < 0 || index > (_size - 1)) {return -1;}
        ListNode* cur = _dummyNode->next;
        while(index--) { // index是从0开始的，第0个是头节点，所以当index等于0的时候，正好cur就是头节点；如果index = 2，0 1 2前面有3个，当前cur是头节点，进入，index = 1, cur是头节点下一个，进入index=0，cur是头节点下2个，第三个，再次就进不去了，此时正好就是index索引位置的节点
            cur = cur->next;
        }
        return cur->val;
    }
    
    // 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val); // 创建新节点
        newNode->next = _dummyNode->next;
        _dummyNode->next = newNode; // 让_dummyNode的下一个指向newNode
        _size++;
       
    }
    
    // 在链表最后面添加一个节点
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyNode;
        while (cur->next != NULL) // 不等于NULL和不等于nullptr是一样的吗
        {
            cur = cur->next; 
        } 
        cur->next = newNode;
        _size++;




        // 这样写无法处理链表为空的情况
        // ListNode* cur = _dummyNode->next;
        // int index = _size;
        // while(index--) {
        //     if(cur->next != NULL) {
        //         cur = cur->next;
        //     }
        // }
        // // 此时cur就是链表最后一个元素,cur->next指向newNode，newNode指向NULL
        // cur->next = newNode;
        // newNode->next = NULL;

       
        
    }
    
    // 在第index个节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
    // 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
    // 如果index大于链表的长度，则返回空
    // 如果index小于0，则在头部插入节点
    void addAtIndex(int index, int val) {
        if(index > _size) {return;}
        if(index < 0) {addAtHead(val); return;} // 要return
        if(index == _size) {addAtTail(val); return;} // 要使用==，然后要return
        // 之前写的不太对：
        // if(index < 0) {addAtHead(val); }
        // if(index = _size) {addAtTail(val); }


        ListNode* newNode = new ListNode(val);// 插入的位置就是再index处。
        // 这样不太好处理下面的插入操作，直接让ListNode* cur = _dummyNode;  而不是后面的：ListNode* cur = _dummyNode->next; // cur从头节点开始；这样如果index=0,说明要插入头节点，正好不会进入while，cur就是要插入的位置。
        ListNode* cur = _dummyNode; 
        while (index--) // index = 1，进入，index= 0 ,cur 为头节点，然后就结束了，newNode就是cur的下一个节点，
        {
            cur = cur->next;
        } // 

        // 循环结束后，cur 指向第 index 个节点的前一个位置（即索引 index-1 的节点）
        newNode->next = cur->next; // 新插入的节点等于cur的下一个
        cur->next = newNode;// cur的下一个等于newNode?

        _size++;        
    }
    
    // 删除第index个节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0) {return;} // 需要加一个index<0的条件才可以。        
        ListNode* cur = _dummyNode;
        while(index--) {
            cur = cur->next;
        }
        // while结束之后，cur是index所在的前一个节点
        ListNode* tmp = cur->next; //要删除的
        cur->next = tmp->next;
        delete tmp;
        _size--;
        //delete命令指示释放了tmp指针原本所指的那部分内存，
        //被delete后的指针tmp的值（地址）并非就是NULL，而是随机值。也就是被delete后，
        //如果不再加上一句tmp=nullptr,tmp会成为乱指的野指针
        //如果之后的程序不小心使用了tmp，会指向难以预想的内存空间
        tmp=nullptr;
        
    }

    // 打印链表：
    void printLinkedList() {
        ListNode* cur = _dummyNode->next; // 可以从头节点开始，这样_size--等于0的时候cur指向最后一个节点
        while(cur != nullptr) { // 错误，这样会链表长度_size，两种该法，一个是int index = _size，另一个是cur != NULL
             std::cout << cur->val << " ";
             cur = cur->next;// 下一个节点
        }
        std::cout << std::endl;
       
       
    }
    
};

int main() {
    MyLinkedList linkedList;

    // 测试用例 1: 空链表 get
    std::cout << "Test 1: get(0) on empty list: " << linkedList.get(0) << " (Expected: -1)" << std::endl;

    // 测试用例 2: addAtHead
    linkedList.addAtHead(1);
    std::cout << "Test 2: addAtHead(1), get(0): " << linkedList.get(0) << " (Expected: 1)" << std::endl;
    linkedList.printLinkedList(); // Expected: 1

    // 测试用例 3: addAtTail
    linkedList.addAtTail(3);
    std::cout << "Test 3: addAtTail(3), get(1): " << linkedList.get(1) << " (Expected: 3)" << std::endl;
    linkedList.printLinkedList(); // Expected: 1 3

    // 测试用例 4: addAtIndex
    linkedList.addAtIndex(1, 2);   // 链表变为1->2->3
    std::cout << "Test 4: addAtIndex(1,2), get(1): " << linkedList.get(1) << " (Expected: 2)" << std::endl;
    linkedList.printLinkedList(); // Expected: 1 2 3

    // 测试用例 5: deleteAtIndex
    linkedList.deleteAtIndex(1);  // 现在链表是1->3
    std::cout << "Test 5: deleteAtIndex(1), get(1): " << linkedList.get(1) << " (Expected: 3)" << std::endl;
    linkedList.printLinkedList(); // Expected: 1 3

    // 测试用例 6: addAtIndex at head (index 0)
    linkedList.addAtIndex(0, 0);
    std::cout << "Test 6: addAtIndex(0,0), get(0): " << linkedList.get(0) << " (Expected: 0)" << std::endl;
    linkedList.printLinkedList(); // Expected: 0 1 3

    // 测试用例 7: addAtIndex at tail (index == size)
    linkedList.addAtIndex(3, 4);
    std::cout << "Test 7: addAtIndex(3,4), get(3): " << linkedList.get(3) << " (Expected: 4)" << std::endl;
    linkedList.printLinkedList(); // Expected: 0 1 3 4

    // 测试用例 8: deleteAtIndex at head
    linkedList.deleteAtIndex(0);
    std::cout << "Test 8: deleteAtIndex(0), get(0): " << linkedList.get(0) << " (Expected: 1)" << std::endl;
    linkedList.printLinkedList(); // Expected: 1 3 4

    // 测试用例 9: deleteAtIndex at tail
    linkedList.deleteAtIndex(2);
    std::cout << "Test 9: deleteAtIndex(2), get(1): " << linkedList.get(1) << " (Expected: 3)" << std::endl;
    linkedList.printLinkedList(); // Expected: 1 3

    // 测试用例 10: 无效索引 get
    std::cout << "Test 10: get(-1): " << linkedList.get(-1) << " (Expected: -1)" << std::endl;
    std::cout << "Test 10: get(10): " << linkedList.get(10) << " (Expected: -1)" << std::endl;

    // 测试用例 11: 无效索引 addAtIndex
    linkedList.addAtIndex(-1, 5); // 应该当作 addAtHead
    std::cout << "Test 11: addAtIndex(-1,5), get(0): " << linkedList.get(0) << " (Expected: 5)" << std::endl;
    linkedList.printLinkedList(); // Expected: 5 1 3

    linkedList.addAtIndex(10, 6); // 无效，不插入
    std::cout << "Test 11: addAtIndex(10,6), size should remain 3, get(3): " << linkedList.get(3) << " (Expected: -1)" << std::endl;
    linkedList.printLinkedList(); // Expected: 5 1 3

    // 测试用例 12: 无效索引 deleteAtIndex
    linkedList.deleteAtIndex(-1); // 不删除
    linkedList.deleteAtIndex(10); // 不删除
    std::cout << "Test 12: deleteAtIndex(-1) and deleteAtIndex(10), list unchanged" << std::endl;
    linkedList.printLinkedList(); // Expected: 5 1 3

    // 测试用例 13: 清空链表
    linkedList.deleteAtIndex(0);
    linkedList.deleteAtIndex(0);
    linkedList.deleteAtIndex(0);
    std::cout << "Test 13: delete all, get(0): " << linkedList.get(0) << " (Expected: -1)" << std::endl;
    linkedList.printLinkedList(); // Expected: (empty)

    return 0;
}