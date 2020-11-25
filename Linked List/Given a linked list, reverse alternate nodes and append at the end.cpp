/*

Complexity Analysis :-

Time Complexity: O(N)
Auxiliary Space: O(1)

*/

Node *reverseHelper(Node *head) {
    if (head == NULL) {
        return NULL;
    }

    Node *prev = NULL;
    Node *mover = head;

    while (mover != NULL) {
        Node *next = mover -> next;
        mover -> next = prev;
        prev = mover;

        mover = next;
    }

    return prev;
}

void rearrange(struct Node *odd)
{

    if (odd == NULL || odd -> next == NULL) {
        return;
    }

    Node *prev = odd;
    int numInfo = 1;

    Node *dummy = new Node(-1);
    Node *dummyHelper = dummy;

    while (odd) {
        if (numInfo % 2 == 0) {
            dummyHelper -> next = odd;
            dummyHelper = dummyHelper -> next;
            prev -> next = odd -> next;
        }
        else {
            prev = odd;
        }
        odd = odd -> next;
        numInfo++;
    }

    dummy -> next = reverseHelper(dummy -> next);
    prev -> next = dummy -> next;
}