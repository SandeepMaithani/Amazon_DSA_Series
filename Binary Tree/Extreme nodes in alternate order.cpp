
/*

Complexity Analysis :-

Time complexity : O(N). Where N is no of nodes in the binary tree we will process each node once.

Space complexity : O(N). We will be using a queue for our level order traversal which will cost O(N) memory.

*/



/*

Intution :-

Key idea here is we will print the alternate first and last element in each level traversal

*/



vector<int> ExtremeNodes(Node* root)
{
    vector<int>answer;
    queue<Node*>bfsHelper;

    if (root == NULL) {
        return answer;
    }

    bool printFirst = false;
    bfsHelper.push(root);

    while (!bfsHelper.empty()) {

        int size = bfsHelper.size();

        for (int i = 0; i < size; i++) {

            Node* currNode = bfsHelper.front();
            bfsHelper.pop();

            if (printFirst == false && i == size - 1) {
                answer.push_back(currNode -> data);
            }
            else if (printFirst == true && i == 0) {
                answer.push_back(currNode -> data);
            }

            if (currNode -> left) {
                bfsHelper.push(currNode -> left);
            }

            if (currNode -> right) {
                bfsHelper.push(currNode -> right);
            }
        }

        printFirst = !printFirst;
    }

    return answer;
}