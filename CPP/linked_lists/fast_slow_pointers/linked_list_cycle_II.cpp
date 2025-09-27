// Linked List Cycle II 
// Pattern: Find start of cycle
// After detecting cycle, reset one pointer to head → move both 1 step → meeting point = cycle start.

#include<iostream>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // cycle found
                // Step 2: Find start of cycle
                slow = head; // reset slow to head
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // both meet at cycle start
            }
        }
        return nullptr; 
    }
};