/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will process each node at max twice.

Space Complexity : O(H), Where H is height of the binary tree and calling stack will used O(H) memory.

*/


/*

Intution :-

We will be using Least common ancesstor to get the minimum distance between two given nodes first we will find the LCA of both the nodes because it is the point where both nodes path first intersect then we will find distance of both the nodes from the LCA and sum of both the nodes distance from LCA will be distance between both the nodes.

*/


Node* getLCA(Node* root, int a, int b) {
    if (root == NULL) {
        return NULL;
    }

    if (root -> data == a || root -> data == b) {
        return root;
    }

    Node* left = getLCA(root -> left, a, b);
    Node* right = getLCA(root -> right, a, b);

    if (left != NULL && right != NULL) {
        return root;
    }

    if (left != NULL) {
        return left;
    }

    if (right != NULL) {
        return right;
    }

    return NULL;
}

void getDistance(Node* lca, int a, int lvl, int& dis) {
    if (lca == NULL) {
        return;
    }

    if (lca -> data == a) {
        dis = lvl;
        return;
    }

    if (dis != -1) {
        return;
    }

    getDistance(lca -> left, a, lvl + 1, dis);
    getDistance(lca -> right, a, lvl + 1, dis);

}

int findDist(Node* root, int a, int b) {
    int adis = -1, bdis = -1;

    Node* lca = getLCA(root, a, b);

    getDistance(lca, a, 0, adis);
    getDistance(lca, b, 0, bdis);

    return adis + bdis;
}