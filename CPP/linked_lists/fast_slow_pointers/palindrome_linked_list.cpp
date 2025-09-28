// Palindrome Linked 
// Pattern: Fast & slow pointer + reversal
// Use fast/slow to reach middle, reverse 2nd half, then compare halves.


#include<iostream>
using namespace std;
//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true; // 0 or 1 node = palindrome

        // Step 1: Find middle (slow at mid)
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Step 3: Compare halves
        ListNode* left = head;
        ListNode* right = prev; // head of reversed half
        while (right) { // only need to check right half
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};