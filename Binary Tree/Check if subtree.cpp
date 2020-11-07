/*

Complexity Analysis :-

Time complexity : O(N*M). In worst case(skewed tree) traverse function takes O(N*M) time.

Space complexity : O(N). We will be using a queue for level order traversal which will cost O(N) memory.

*/


/*

Intution :-

Key idea here is we will check each and every node whose value is equal to data of root node then we will check weather subtree starting from that node is identical to given subtree or not.

*/


bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }

    if ((root1 != NULL && root2 == NULL) || (root1 == NULL && root2 != NULL)) {
        return false;
    }

    if (root1 -> data != root2 -> data) {
        return false;
    }

    if (isIdentical(root1 -> left, root2 -> left) && isIdentical(root1 -> right, root2 -> right)) {
        return true;
    }

    return false;
}


bool isSubTree(Node* T, Node* S) {
    if (T == NULL && S == NULL) {
        return true;
    }

    if ((T != NULL && S == NULL) || (T == NULL && S != NULL)) {
        return false;
    }

    queue<Node*>bfsHelper;
    bfsHelper.push(T);

    while (!bfsHelper.empty()) {
        Node* currNode = bfsHelper.front();
        bfsHelper.pop();

        if (currNode -> data == S -> data) {
            bool isSub = isIdentical(currNode, S);

            if (isSub) {
                return true;
            }
        }

        if (currNode -> left != NULL) {
            bfsHelper.push(currNode -> left);
        }

        if (currNode -> right != NULL) {
            bfsHelper.push(currNode -> right);
        }
    }

    return false;

}