/*

Complexity Analysis:

Time complexity : O(N), Where N is number of nodes in the binary tree and we will be visiting each node once.

Space Complexity : O(H), Where H is height of tree which is the space required by calling stack during recursion calls.

*/


/*

Intution :-

Key idea here is we will first convert binary tree to doubly linked list inplace by keeping track of head and tail pointer
and after completing our doubly linked list we will be joining head left to tail and tail right part to the head of the doubly linked list.

*/


void treeToCDLL(Node *root, Node *&head, Node *&tail) {
    if (root == NULL) {
        return;
    }

    treeToCDLL(root -> left, head, tail);

    if (head == NULL) {
        head = root;
    }
    else {
        tail -> right = root;
        root -> left = tail;
    }

    tail = root;

    treeToCDLL(root -> right, head, tail);
}

Node *bTreeToCList(Node *root)
{
    if (root == NULL) {
        return NULL;
    }

    Node *head = NULL;
    Node *tail = NULL;

    treeToCDLL(root, head, tail);

    head -> left = tail;
    tail -> right = head;

    return head;
}