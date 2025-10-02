#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
    if(!headA || !headB) return nullptr;

    ListNode* pA = headA;
    ListNode* pB = headB;

    while(pA != pB) {
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }

    return pA;  // could be nullptr if no intersection
}

int main() {
    // Example setup
    ListNode* a1 = new ListNode(4);
    ListNode* a2 = new ListNode(1);
    ListNode* b1 = new ListNode(5);
    ListNode* b2 = new ListNode(6);
    ListNode* b3 = new ListNode(1);
    ListNode* c1 = new ListNode(8);
    ListNode* c2 = new ListNode(4);
    ListNode* c3 = new ListNode(5);

    // Connect lists
    a1->next = a2; a2->next = c1;
    b1->next = b2; b2->next = b3; b3->next = c1;
    c1->next = c2; c2->next = c3;

    ListNode* intersect = getIntersectionNode(a1, b1);
    if(intersect)
        cout << "Intersection at node with value: " << intersect->val << endl;
    else
        cout << "No intersection" << endl;
}

Pattern here: Two-pointer alignment
You have 2 lists, maybe they intersect.
Problem: they might have different lengths.
Trick:
Pointer A walks list A, then switches to head of B.
Pointer B walks list B, then switches to head of A.
Both now walk the same total distance (lenA + lenB).
Why it works
If intersection exists → they’ll land on the same node after alignment.
If no intersection → both hit null at the same time.

💡 Essence: This problem checks if you know how to handle unequal lengths of linked lists without extra space.
If the two lists have equal lengths:

You don’t even need the switching trick.

Just move pA and pB step by step.

If there’s an intersection, they’ll meet naturally at the same time.

If no intersection, they’ll both reach null together.

👉 The switching trick is only to fix the unequal lengths case.
When lengths are equal, the trick still works — they just won’t switch because they hit the end at the same time.

So:

Equal lengths → simple parallel walk works.

Unequal lengths → switching aligns them (core idea of this pattern).
ChatGPT said:

If there’s no intersection:

Both pointers still walk exactly lenA + lenB steps.

After switching lists, they eventually both hit nullptr.

Since nullptr == nullptr, the loop ends, and we know no intersection exists.

So outcomes are only two:

They meet at a node → intersection found.

They both become null at the same step → no intersection.

💡 Essence: the switching trick guarantees they’ll either meet at intersection or end at null together.