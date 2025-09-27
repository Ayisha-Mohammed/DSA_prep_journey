// Middle of the Linked List 
// Pattern: Find middle using fast & slow
// slow = 1 step, fast = 2 steps → when fast hits end, slow = middle.

#include<iostream>
using namespace std;


struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val):data(val), next(nullptr) {};
    
};
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         // move 1 step
            fast = fast->next->next;   // move 2 steps
        }
        return slow; // when fast reaches end, slow is middle
    }
};