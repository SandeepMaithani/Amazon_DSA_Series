/*

Complexity analysis :-

Time complexity : O(N + M). Where N and M are No of Nodes in the first and second linkedList representing the polynomial equation, and we will visit each node once from each node and merging its nodes in single list it will cost O(N + M) time.

Space complexity : O(1). Since we are not using any extra space it will use constant memory..

*/


/*

Intution :-

Basic idea here is we can use concept of merging two sorted linked list with some changes and that will be whenever we will nodes with equal power from both the linked list we simply add there coefficient in any of the node and then merge that node in resultant node. and we keep on merging nodes based on there power value.

*/


Node* addPolynomial(Node *p1, Node *p2)
{
    if (p1 == NULL && p2 == NULL) {
        return NULL;
    }

    if (p1 == NULL && p2 != NULL) {
        return p2;
    }

    if (p1 != NULL && p2 == NULL) {
        return p1;
    }

    Node* firstHelper = p1;
    Node* secondHelper = p2;

    Node* dummy = new Node(0, 0);
    Node* polyHelper = dummy;

    while (firstHelper != NULL && secondHelper != NULL) {
        if (firstHelper -> pow > secondHelper -> pow) {
            polyHelper -> next = firstHelper;
            firstHelper = firstHelper -> next;
        }
        else if (secondHelper -> pow > firstHelper -> pow ) {
            polyHelper -> next = secondHelper;
            secondHelper = secondHelper -> next;
        }
        else {
            firstHelper -> coeff = firstHelper -> coeff + secondHelper -> coeff;
            polyHelper -> next = firstHelper;

            firstHelper = firstHelper -> next;
            secondHelper = secondHelper -> next;
        }

        polyHelper = polyHelper -> next;
    }

    while (firstHelper != NULL) {
        polyHelper -> next = firstHelper;
        firstHelper = firstHelper -> next;
    }

    while (secondHelper != NULL) {
        polyHelper -> next = secondHelper;
        secondHelper = secondHelper -> next;
    }

    return dummy -> next;
}