/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will visit each nodes at max 2 times.

Space Complexity : O(H), Where H is height of the tree which is space used by calling stack.

*/

/*

Intution :-

First we get the root data then we will get all the leftMost elements from the left subtree of given root by moving left each time in a
top - down manner, then we wil get all leaf nodes from left subtree using inOrder traversal similary we can get all leaf nodes of right subtree of given root then we will get all the rightMost element of the right subtree of the given root by moving toward right each time in a bottom - up manner.

*/


void leftBoundary(Node* root, vector<int>& boundary) {
    if (root == NULL) {
        return;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return;
    }

    boundary.push_back(root -> data);

    if (root -> left != NULL) {
        leftBoundary(root -> left, boundary);
    }
    else {
        leftBoundary(root -> right, boundary);
    }

}

void rightBoundary(Node* root, vector<int>& boundary) {
    if (root == NULL) {
        return;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return;
    }

    if (root -> right != NULL) {
        rightBoundary(root -> right, boundary);
    }
    else {
        rightBoundary(root -> left, boundary);
    }

    boundary.push_back(root -> data);

}

void leafNodes(Node* root, vector<int>& boundary) {

    if (root == NULL) {
        return;
    }

    leafNodes(root -> left, boundary);

    if (root -> left == NULL && root -> right == NULL) {
        boundary.push_back(root -> data);
    }

    leafNodes(root -> right, boundary);

}

vector <int> printBoundary(Node *root)
{
    vector<int>boundary;

    if (root == NULL) {
        return boundary;
    }

    boundary.push_back(root -> data);

    leftBoundary(root -> left, boundary);

    leafNodes(root -> left, boundary);
    leafNodes(root -> right, boundary);

    rightBoundary(root -> right, boundary);

    return boundary;
}