/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will process each node once.

Space Complexity : O(N), Where N is no of nodes in the binary tree we will create a new TreeNode for each of the linked list node and store them in a vector which will cost O(N) memory.

*/


/*

Intution :-

First we will extract data from the linked list and create new TreeNode for each linked list node store them in a vector now we know If root node is stored at index i, its left, and right children are stored at indices 2*i+1, 2*i+2 respectively now based on this property of complete binary tree we can easily connect left and right child of each binary tree node.


*/



void convert(Node *head, TreeNode *&root) {

    if (head == NULL) {
        return;
    }

    vector<TreeNode*>nodeKeeper;

    while (head != NULL) {

        int nodeData = head -> data;

        TreeNode* newNode = new TreeNode(nodeData);
        nodeKeeper.push_back(newNode);

        head = head -> next;
    }

    int size = nodeKeeper.size();

    for (int i = 0; i < size / 2; i++) {

        int leftIndex = (2 * i) + 1;
        int rightIndex = (2 * i) + 2;

        if (leftIndex < size) {
            nodeKeeper[i] -> left = nodeKeeper[leftIndex];
        }

        if (rightIndex < size) {
            nodeKeeper[i] -> right = nodeKeeper[rightIndex];
        }
    }

    root = nodeKeeper[0];
}