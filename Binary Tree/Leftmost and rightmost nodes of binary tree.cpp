/*

Method : Level order traversal                              Verdict : Accepted

Complexity Analysis:

Time complexity : O(N), We will be doing a level order traversal that will cost O(N) time and print first and last Node of each level.

Space Complexity : O(No of nodes in a level), We will be using a queue for level order traversal that will have size of maximum nodes present at any level.

*/



void printCorner(Node *root)
{
    if (root == NULL) {
        return;
    }

    queue<Node *>bfsHelper;
    bfsHelper.push(root);

    while (!bfsHelper.empty()) {
        int size = bfsHelper.size();

        for (int i = 0; i < size; i++) {

            Node* currentNode = bfsHelper.front();
            bfsHelper.pop();

            if (i == 0 || i == size - 1) {
                cout << currentNode -> data << " ";
            }

            if (currentNode -> left != NULL) {
                bfsHelper.push(currentNode -> left);
            }

            if (currentNode -> right != NULL) {
                bfsHelper.push(currentNode -> right);
            }
        }
    }
}