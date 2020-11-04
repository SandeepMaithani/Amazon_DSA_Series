/*

Method : Using Hashing                             Verdict : Accepted

Complexity Analysis:

Time complexity : O(N), We will create new node and map node address correspond to index in a hashMap or we can use vector as a hashMap and later assign connection with corresponding parent.

Space Complexity : O(N), We will be using a hashMap or vector as a hashMap to map node address corresponding to its index value.

*/


/*

Intution :-

here is we will create node with index value and map the address of node with its index now based on our mapping we can easily create connection for its children.

*/



Node *createTree(int parent[], int n)
{
    unordered_map<int, Node*>hashMap;
    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        Node* temp = new Node(i);
        hashMap[i] = temp;
    }

    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = hashMap[i];
        }
        else {
            if (hashMap[parent[i]] -> left == NULL) {
                hashMap[parent[i]] -> left = hashMap[i];
            }
            else {
                hashMap[parent[i]] -> right = hashMap[i];
            }
        }
    }
    return root;
}