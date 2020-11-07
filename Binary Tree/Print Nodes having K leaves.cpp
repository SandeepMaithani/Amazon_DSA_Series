/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will process each node once.

Space Complexity : O(H), Where H is height of the binary tree and calling stack will use O(H) memory.

*/


/*

Intution :-

Key idea here is each child will give info of how many leaves it have to its parent no of leaves for a parent will be equal to leaves of its left child + leaf of its right child and if any node have no of leaves equal to given no K we will store its data

*/


int leafCounter(Node *root, int k, vector<int>& answer) {
    if (root == NULL ) {
        return 0;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return 1;
    }

    int leftLeaf = leafCounter(root -> left, k, answer);
    int rightLeaf = leafCounter(root -> right, k, answer);

    int totalLeaf = leftLeaf + rightLeaf;

    if (totalLeaf == k) {
        answer.push_back(root -> data);
    }

    return totalLeaf;
}

vector<int> btWithKleaves(Node *ptr, int k)
{
    vector<int>answer;

    if (ptr == NULL) {
        return { -1};
    }

    int treeLeafCount = leafCounter(ptr, k, answer);

    if (answer.size() == 0) {
        return { -1};
    }

    return answer;
}