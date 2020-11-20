/*

Method : By Reversing the Linked List                    Verdict : Accepted

Complexity analysis

Time complexity : O(N). Assume that N is the list's length, the time complexity is O(N).

Space complexity : O(1). No extra Space required.

*/



/*

Intution :-

what we are going to do here is :-

1. Reverse the Linked List.

2. take a variable max and assign head node data of newly reversed list now we will Traverse the Linked List again and update MAX at each iteration and delete a node if it has a lesser value than MAX by maintaining a PREVIOUS node.

3. Reverse the Linked List again.


*/



Node *reverseHelper(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *prev = NULL;
    Node *mover = head;

    while (mover) {
        Node *next = mover -> next;
        mover -> next = prev;
        prev = mover;
        mover = next;
    }

    return prev;
}


Node *computeHelper(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *mover = head;
    Node *prev = NULL;
    int maxVal = head -> data;

    while (mover != NULL) {
        if ((mover -> data < maxVal)) {
            if (mover == head) {
                head = mover -> next;
            }
            else {
                prev -> next = mover -> next;
            }
        }
        else {
            prev = mover;
            maxVal = mover -> data;
        }
        mover = mover -> next;
    }

    return head;
}


Node *compute(Node *head)
{
    if (head == NULL) {
        return NULL;
    }

    head = reverseHelper(head);
    head = computeHelper(head);
    head = reverseHelper(head);

    return head;
}
