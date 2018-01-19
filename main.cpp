//
//  main.cpp
//  LeetCode143_ReorderList
//
//  Created by Rui on 1/18/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        ListNode* last = mid;
        slow->next = NULL;
        ListNode* pre = NULL;
        
        while(last){
            ListNode* next = last->next;
            last->next = pre;
            pre = last;
            last = next;
        }
        while(head && pre){
            ListNode* next = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = next;
            head = next;
        }
        
    }
};
