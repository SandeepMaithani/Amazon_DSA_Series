/*

Method : - Hashing(Map clone node with corresponding node in original tree)            verdict : Accepted

Complexity Analysis :-

Time complexity : O(N). Where N is no of nodes in the binary tree we will process each node once.

Space complexity : O(N). We will be using a hashtable to map clone node with original node which will cose O(N) memory.

*/


/*

Intution :-

Key idea here is we will map new cloned node with its original nodes and based on this mapping wherever the parent node points we will make connection in its clone node according to original tree.

*/


void preOrder(Node* tree, unordered_map<Node*, Node*>&hashMap) {

    if (tree == NULL) {
        return;
    }

    hashMap[tree] = new Node(tree -> data);

    preOrder(tree -> left, hashMap);
    preOrder(tree -> right, hashMap);
}

void cloneChild(Node* tree, unordered_map<Node*, Node*>&hashMap) {

    if (tree == NULL) {
        return;
    }

    if (tree -> left != NULL) {
        hashMap[tree] -> left = hashMap[tree -> left];
    }
    else {
        hashMap[tree] -> left = NULL;
    }

    if (tree -> right != NULL) {
        hashMap[tree] -> right = hashMap[tree -> right];
    }
    else {
        hashMap[tree] -> right = NULL;
    }

    if (tree -> random != NULL) {
        hashMap[tree] -> random = hashMap[tree -> random];
    }
    else {
        hashMap[tree] -> random = NULL;
    }

    cloneChild(tree -> left, hashMap);
    cloneChild(tree -> right, hashMap);
}

Node* cloneTree(Node* tree)
{
    if (tree == NULL) {
        return NULL;
    }

    Node* newTree = NULL;
    unordered_map<Node*, Node*>hashMap;

    preOrder(tree, hashMap);
    cloneChild(tree, hashMap);

    newTree = hashMap[tree];

    return newTree;
}