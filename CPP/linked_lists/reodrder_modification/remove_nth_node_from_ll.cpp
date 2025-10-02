#include <iostream>
using namespace std;
//  Definition for singly-linked list.
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
        ListNode* dummy = new ListNode(0, head);
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        // Move fast n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        
        // Move both until fast reaches end
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // Remove nth node
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete;  // free memory
        
        ListNode* newHead = dummy->next;
        delete dummy;  // free dummy
        return newHead;
    }
};
























// 1️⃣ Problem Statement

// Given:
// A singly linked list head and an integer n.

// Task:
// Remove the nth node from the end of the list.
// Return the head of the updated list.

// Constraints / Notes:
// n is always valid (1 ≤ n ≤ length of list).
// Try to do it in one pass.

// Example:

// Input: head = 1->2->3->4->5, n = 2
// Output: 1->2->3->5
// Explanation: 2nd node from end is 4, remove it.

// 2️⃣ Idea / Pattern

// Use two pointers (fast & slow).
// Move fast pointer n steps ahead first.
// Then move slow and fast together until fast reaches the end.
// At this point, slow is just before the node to delete.
// Update links: slow->next = slow->next->next.
// Trick: Use a dummy node before head to handle edge cases (like deleting the head itself).
// Pattern Name: Two-pointer / Fast & Slow pointer.

// 3️⃣ Algorithm (Step-by-Step)

// Create a dummy node pointing to head.
// Initialize slow and fast at dummy.
// Move fast n+1 steps ahead.
// Move slow and fast together until fast reaches nullptr.
// slow->next is the node to delete. Remove it:
// ListNode* nodeToDelete = slow->next
// slow->next = slow->next->next;
// delete nodeToDelete;
// Return dummy->next as the new head.