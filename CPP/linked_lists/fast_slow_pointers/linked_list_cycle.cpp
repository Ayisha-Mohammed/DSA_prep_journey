// Linked List Cycle 
// 🔹 Pattern: Cycle detection (Floyd’s Tortoise & Hare)
// If fast == slow at some point → cycle exists.


#include<iostream>
using namespace std;


struct ListNode{
    int data;
    ListNode* next;
    ListNode(int val):data(val), next(nullptr) {};
    
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false; // no nodes or single node can't form a cycle

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;           // 1 step
            fast = fast->next->next;     // 2 steps

            if (slow == fast) return true; // cycle detected
        }
        return false; // reached end → no cycle
    }
};