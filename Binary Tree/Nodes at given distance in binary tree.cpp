class solver
{
private:

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

        bool left = kNodesHelper(root -> left, bfsHelper, target, k, solution, nodeDistance);
        bool right = kNodesHelper(root -> right, bfsHelper, target, k, solution, nodeDistance);

        if (left) {
            int size = bfsHelper.size();
            nodeDistance++;
            cout << nodeDistance << endl;

            while (size--) {
                Node* currNode = bfsHelper.front();
                bfsHelper.pop();

                if (nodeDistance == k) {
                    solution.push_back(currNode -> data);
                }

                cout << nodeDistance << "   " << currNode -> data << endl;

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

            return true;
        }

        if (right) {
            int size = bfsHelper.size();
            nodeDistance++;

            cout << nodeDistance << endl;

            while (size--) {
                Node* currNode = bfsHelper.front();
                bfsHelper.pop();

                if (nodeDistance == k) {
                    solution.push_back(currNode -> data);
                }

                cout << nodeDistance << "   " << currNode -> data << endl;

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