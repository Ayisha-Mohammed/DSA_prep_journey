#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to reverse first k nodes recursively
Node* reverseKGroup(Node* head, int k) {
    Node* curr = head;
    int count = 0;

    // Check if there are at least k nodes
    while (curr != nullptr && count < k) {
        curr = curr->next;
        count++;
    }
    if (count < k) return head; // Less than k nodes, return head as is

    // Reverse first k nodes
    Node* prev = nullptr;
    Node* next = nullptr;
    curr = head;
    count = 0;
    while (curr != nullptr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Now head is the last node of reversed group
    // Recurse for remaining nodes
    if (next != nullptr) {
        head->next = reverseKGroup(next, k);
    }

    // prev is the new head of the reversed group
    return prev;
}

// Helper function to print linked list
// void printList(Node* head) {
//     while (head) {
//         cout << head->data << " -> ";
//         head = head->next;
//     }
//     cout << "NULL" << endl;
// }

int main() {
    // Example linked list: 1->2->3->4->5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int k = 2;
    cout << "Original List: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
