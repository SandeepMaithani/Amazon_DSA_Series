/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will visit each node once.

Space Complexity : O(H), Where H is height of the tree which is space used by calling stack.

*/



/*

Intution :-

Key Idea here is we will recursively traverse to the leftmost node and maintain a bool variable to signal its parent
in order to delete its child or not when we get a leaf node we will do our process of converting node to DLL and
change bool variable to true and after each left and right call we will check weather we have to delete its child
or not and if we have to delete it then after deletion we will mark bool variable as false and we will do this
recursively.

*/


void leavesToDLL(Node *root, Node* &head, Node* &curr, bool &nodeRemover) {
    if (root == NULL) {
        return;
    }

    if (root -> left == NULL && root -> right == NULL) {

        if (head == NULL) {
            head = root;
        }
        else {
            root -> left = curr;
            curr -> right = root;
        }

        curr = root;
        nodeRemover = true;
        return;
    }

    leavesToDLL(root -> left, head, curr, nodeRemover);

    if (nodeRemover == true) {
        root -> left = NULL;
        nodeRemover = false;
    }

    leavesToDLL(root -> right, head, curr, nodeRemover);

    if (nodeRemover == true) {
        root -> right = NULL;
        nodeRemover = false;
    }
}


Node * convertToDLL(Node *root) {

    Node* head = NULL;
    Node* curr = NULL;
    bool nodeRemover = false;

    leavesToDLL(root, head, curr, nodeRemover);

    return head;
}