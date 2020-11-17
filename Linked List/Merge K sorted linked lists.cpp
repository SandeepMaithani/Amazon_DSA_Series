/*

Method 2 : using merge two linked List                            Verdict : Accepted

Complexity Analysis:

Time complexity : O(N^2), where N is total number of nodes, i.e., N = kn.

Space Complexity : O(1), As no extra space is required.

*/


/*

Intution :-

Key idea here is we will pick all the linked list one by one and merge them with the so formed resulted merge list
after merging all the linked list with the method of merge two linked list we will get the final merged linked list.

*/


Node* mergeTwoList(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    Node* dummy = new Node(0);
    Node* merger = dummy;

    while (head1 != NULL && head2 != NULL) {

        if (head1 -> data <= head2 -> data) {
            merger -> next = head1;
            head1 = head1 -> next;
        }
        else {
            merger -> next = head2;
            head2 = head2 -> next;
        }

        merger = merger -> next;
    }

    while (head1 != NULL) {
        merger -> next = head1;
        head1 = head1 -> next;
        merger = merger -> next;
    }

    while (head2 != NULL) {
        merger -> next = head2;
        head2 = head2 -> next;
        merger = merger -> next;
    }

    return dummy -> next;
}

Node * mergeKLists(Node *arr[], int N)
{
    if (N == 0) {
        return NULL;
    }

    if (N == 1) {
        return arr[0];
    }

    Node * mergeList = mergeTwoList(arr[0], arr[1]);

    for (int i = 2; i < N; i++) {
        mergeList = mergeTwoList(arr[i], mergeList);
    }

    return mergeList;
}