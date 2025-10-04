#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Solution class
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;

        // Step 1: Find length and tail
        int n = 1;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: Make circular
        tail->next = head;

        // Step 3: Find new tail
        k = k % n;
        int stepsToNewTail = n - k - 1;
        ListNode* newTail = head;
        for(int i = 0; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Set new head and break circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Driver code
int main() {
    // Create example list: 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    int k = 2; // Rotate by 2
    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    // Free remaining nodes
    while(head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }

    return 0;
}
