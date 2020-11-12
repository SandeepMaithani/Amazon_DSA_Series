/*

Complexity Analysis:

Time complexity : O(N), Where N is size of given array and we will process each element once.

Space Complexity : O(N), We will we creating a tree of N nodes so total N new nodes will be there.

*/


/*

Intution :-

Key idea here is at every node we will check weather it is a leaf node of not if it is leaf node then we will assign NULL to its left and right child else we will increment the preorder array index and recursive do the same procedure for left and child for the current node and in the end we will return the root node in each call.

*/


Node* preToTree(int n, int &ind, int pre[], char preLN[]) {
    if (n <= ind) {
        return NULL;
    }

    Node* root = new Node(pre[ind]);

    if (preLN[ind] == 'N') {
        ind++;
        root -> left = preToTree(n, ind, pre, preLN);
        root -> right = preToTree(n, ind, pre, preLN);
    }
    else {
        ind++;
        root -> left = NULL;
        root -> right = NULL;
    }

    return root;
}

struct Node *constructTree(int n, int pre[], char preLN[])
{
    int ind = 0;

    return preToTree(n, ind, pre, preLN);
}