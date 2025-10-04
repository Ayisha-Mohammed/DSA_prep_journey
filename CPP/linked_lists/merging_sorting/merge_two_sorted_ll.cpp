#include<iostream>
using namespace std;


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* dummy = new ListNode(-1);
         ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return dummy->next;
    }
};













//LeetCode 21 – Merge Two Sorted Lists

// Problem:
// You are given two sorted linked lists.
// Merge them into one sorted linked list.

// Approach:
// Use two pointers: l1 and l2.
// Compare values at both pointers.
// Attach smaller node to the merged list and move that pointer.
// Continue until one list ends, then attach remaining nodes.

// Complexity:
// Time: O(n + m) (n, m = lengths of the lists)
// Space: O(1) if in-place (iterative)