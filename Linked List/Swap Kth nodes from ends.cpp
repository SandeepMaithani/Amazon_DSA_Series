/*

Complexity analysis :-

Time complexity : O(N). Assume that N is the list's length, the time complexity is O(N).

Space complexity : O(1). No extra Space required.

*/


/*

Intution :-

Basic idea here is first we will find the position of both the Kth node from end and start and then we will
store the address of start kth node and its previous node similarly we will do for end Kth node and its previous
node and after getting those node we will handle the base condition like first node dont have any previous node
in that case node to be swapped with first node will become new head and then make the connection change for both
the end and start kth node.

*/

Node *swapkthnode(Node* head, int num, int k)
{
    if (head == NULL) {
        return NULL;
    }

    if (num < k) {
        return head;
    }

    int startPos = k;
    int endPos = num - k + 1;
    int curPos = 1;

    Node* mover = head;
    Node* prev = NULL;
    Node* start = NULL;
    Node* end = NULL;
    Node* startPrev = NULL;
    Node* endPrev = NULL;

    while (mover) {
        if (curPos == startPos) {
            start = mover;
            startPrev = prev;
        }
        if (curPos == endPos) {
            end = mover;
            endPrev = prev;
        }

        prev = mover;
        mover = mover -> next;
        curPos++;
    }

    if (startPrev != NULL) {
        startPrev -> next = end;
    }
    else {
        head = end;
    }

    if (endPrev != NULL) {
        endPrev -> next = start;
    }
    else {
        head = start;
    }

    Node *temp = start -> next;
    start -> next = end -> next;
    end -> next = temp;

    return head;
}
