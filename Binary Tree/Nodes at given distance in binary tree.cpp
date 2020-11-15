/*

Complexity Analysis:

Time complexity : O(N), Where N is number of nodes in the binary tree and we will be visiting each node at most twice.

Space Complexity : O(H), Where H is height of tree which is the space required by calling stack during recursion calls.

*/


/*

Intution :-

Key idea here is we will use the concept of time required to burn a tree time required to burn an individual node
is the distance of that node from target node so we will look for the node whose distance or burn time is K from the
target node and we will get our solution.

*/


class solver
{

public:

    bool kNodesHelper(Node* root, queue<Node*> &bfsHelper, int target, int k, vector<int> &solution, int &nodeDistance) {

        if (root == NULL) {
            return false;
        }

        if (root -> data == target) {

            if (root -> left != NULL) {
                bfsHelper.push(root -> left);
            }
            if (root -> right != NULL) {
                bfsHelper.push(root -> right);
            }

            return true;
        }

        bool inleft = kNodesHelper(root -> left, bfsHelper, target, k, solution, nodeDistance);
        bool inright = kNodesHelper(root -> right, bfsHelper, target, k, solution, nodeDistance);

        if (inleft) {
            int size = bfsHelper.size();
            nodeDistance++;

            while (size--) {
                Node* currNode = bfsHelper.front();
                bfsHelper.pop();

                if (nodeDistance == k) {
                    solution.push_back(currNode -> data);
                }

                if (currNode -> left) {
                    bfsHelper.push(currNode -> left);
                }

                if (currNode -> right) {
                    bfsHelper.push(currNode -> right);
                }
            }

            if (root -> right) {
                bfsHelper.push(root -> right);
            }

            if (nodeDistance == k) {
                solution.push_back(root -> data);
            }

            return true;
        }

        if (inright) {
            int size = bfsHelper.size();
            nodeDistance++;

            while (size--) {
                Node* currNode = bfsHelper.front();
                bfsHelper.pop();

                if (nodeDistance == k) {
                    solution.push_back(currNode -> data);
                }

                if (currNode -> left) {
                    bfsHelper.push(currNode -> left);
                }

                if (currNode -> right) {
                    bfsHelper.push(currNode -> right);
                }
            }

            if (root -> left) {
                bfsHelper.push(root -> left);
            }

            if (nodeDistance == k) {
                solution.push_back(root -> data);
            }

            return true;
        }

        return false;
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> solution;
        int nodeDistance = 0;
        queue<Node*>bfsHelper;

        if (root == NULL) {
            return solution;
        }


        bool dummy = kNodesHelper(root, bfsHelper, target, k, solution, nodeDistance);

        while (!bfsHelper.empty()) {
            int size = bfsHelper.size();
            nodeDistance++;

            for (int i = 0; i < size; i++) {
                Node* currNode = bfsHelper.front();
                bfsHelper.pop();

                if (nodeDistance == k) {
                    solution.push_back(currNode -> data);
                }

                if (currNode -> left != NULL) {
                    bfsHelper.push(currNode -> left);
                }

                if (currNode -> right != NULL) {
                    bfsHelper.push(currNode -> right);
                }
            }
        }

        return solution;
    }
};