/*

Method  : Using Reverse Inorder Traversal                                Verdict : Accepted

Complexity Analysis:

Time complexity : O(N),  As Each node is traversed only once.

Space Complexity : O(N) or O(1), in the worst case of completely unbalanced tree, to keep a recursion stack and if
we ignore in calling stack space then it will take O(1) extra space.

*/


void modifyHelper(Node *root, int& adder) {
    if (root == NULL) {
        return;
    }

    modifyHelper(root -> right, adder);

    root -> data = root -> data + adder;
    adder = root -> data;

    modifyHelper(root -> left, adder);
}

Node* modify(Node *root)
{
    int adder = 0;

    modifyHelper(root, adder);

    return root;
}