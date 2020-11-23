/*

Complexity analysis :-

Time complexity : O(N). Where N is the No of Nodes in the Linked list, and we will visit each node exactly once.

Space complexity : O(1). No extra Space required.

*/



/*

Intution :-

Key Idea here is we will maintain a prev pointer which will point to previous node and whenever we will find a node whose data is equal to given value we will eliminate that node from the list by making previous node next pointer point to next node of current pointer.

*/



Node* deleteAllOccurances(Node *head, int x)
{
    if (head == NULL) {
        return NULL;
    }

    Node* mover = head;
    Node* prev = NULL;

    while (mover) {
        if (mover -> data == x) {
            if (mover == head) {
                head = mover -> next;
            }
            else {
                prev -> next = mover -> next;
            }
        }
        else {
            prev = mover;
        }
        mover = mover -> next;
    }

    return head;
}