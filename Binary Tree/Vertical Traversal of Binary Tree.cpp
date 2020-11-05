/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will process each node once.

Space Complexity : O(N), Where N is no of nodes in the binary tree and we will we using hashMap to store at max N nodes in the hashTable.

*/


/*

Intution :-

Here we will divide each element based on a vertical line or we can say distance from root node and after doing a level order traversal
we will use hashTable to map NodeData corresponds to its respective distance from root and and also get the min distance and max distance
and then will print node data from min level to max level.

*/



vector<int> verticalOrder(Node *root)
{
    vector<int>solution;
    unordered_map<int, vector<int>>hashMap;
    queue<pair<Node*, int>>bfsHelper;

    if (root == NULL) {
        return solution;
    }

    int minLevel = 0, maxLevel = 0;

    bfsHelper.push({root, 0});

    while (!bfsHelper.empty()) {
        Node* currNode = bfsHelper.front().first;
        int level = bfsHelper.front().second;

        bfsHelper.pop();

        hashMap[level].push_back(currNode -> data);

        if (minLevel > level) {
            minLevel = level;
        }

        if (maxLevel < level) {
            maxLevel = level;
        }

        if (currNode -> left != NULL) {
            bfsHelper.push({currNode -> left, level - 1});
        }

        if (currNode -> right != NULL) {
            bfsHelper.push({currNode -> right, level + 1});
        }
    }

    for (int i = minLevel; i <= maxLevel; i++) {
        for (int data : hashMap[i]) {
            solution.push_back(data);
        }
    }

    return solution;
}
