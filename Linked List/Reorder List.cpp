/*

Complexity analysis :-

Time complexity : O(N). Where N is the No of Nodes in the Linked list, and we will visit any node atmost twice.

Space complexity : O(1). We are not going to use any extra memory.

*/


/*

Intution :-

1) Find the middle point using tortoise and hare method.
2) Split the linked list into two halves using found middle point in step 1.
3) Reverse the second half.
4) Do alternate merge of first and second halves.

*/


Node* reverseList(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* prev = NULL;
    Node* mover = head;

    while (mover != NULL) {
        Node* next = mover -> next;
        mover -> next = prev;
        prev = mover;
        mover = next;
    }

    return prev;
}

void reorderList(Node* head) {
    if (head == NULL || head -> next == NULL || head -> next -> next == NULL) {
        return;
    }

    Node* slow = head;
    Node* fast = slow -> next;;

    while (fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* list1 = head;
    Node* list2 = slow -> next;
    slow -> next = NULL;

    list2 = reverseList(list2);

    Node* dummy = new Node(-1);
    Node* dummyHelper = dummy;

    while (list1 != NULL || list2 != NULL) {
        if (list1) {
            dummyHelper -> next = list1;
            list1 = list1 -> next;
            dummyHelper = dummyHelper -> next;
        }
        if (list2) {
            dummyHelper -> next = list2;
            list2 = list2 -> next;
            dummyHelper = dummyHelper -> next;
        }
    }

    head = dummy -> next;
}