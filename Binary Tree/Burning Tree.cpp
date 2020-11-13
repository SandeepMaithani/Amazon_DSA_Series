/*

Complexity Analysis:

Time complexity : O(N), Where N is number of nodes in the binary tree.

Space Complexity : O(H), Where H is height of tree which is the space required by calling stack during recursion calls.

*/


/*

Intution :-

Key idea here is we will traverse the tree in a post order manner and look for the desired target node once we get the
target node we will return true that this perticular side(left/Right) have the target node and start burning tree in a
level order manner we will burn the tree and push its child in queue and before return we will check if target is present
on left side the we will push it right sibling if present or if target is at left then we push its right sibling and afte
return from root we will burn remaining node from queue if exist from main.

*/


bool treeBurner(Node* root, int target, queue<Node*>&bfsHelper, int &minTime) {
    if (root == NULL) {
        return false;
    }

    if (root -> data == target) {
        if (root ->left) {
            bfsHelper.push(root -> left);
        }
        if (root -> right) {
            bfsHelper.push(root -> right);
        }

        return true;
    }

    bool inLeft = treeBurner(root -> left, target, bfsHelper, minTime);
    bool inRight = treeBurner(root -> right, target, bfsHelper, minTime);

    if (inLeft) {
        int size = bfsHelper.size();
        minTime++;

        while (size--) {
            Node* burnNode = bfsHelper.front();
            bfsHelper.pop();

            if (burnNode -> left != NULL) {
                bfsHelper.push(burnNode -> left);
            }

            if (burnNode -> right != NULL) {
                bfsHelper.push(burnNode -> right);
            }
        }

        if (root -> right != NULL) {
            bfsHelper.push(root -> right);
        }

        return true;
    }

    if (inRight) {
        int size = bfsHelper.size();

        minTime++;

        while (size--) {
            Node* burnNode = bfsHelper.front();
            bfsHelper.pop();

            if (burnNode -> left != NULL) {
                bfsHelper.push(burnNode -> left);
            }

            if (burnNode -> right != NULL) {
                bfsHelper.push(burnNode -> right);
            }
        }

        if (root -> left != NULL) {
            bfsHelper.push(root -> left);
        }

        return true;
    }

    return false;
}

int minTime(Node* root, int target)
{
    int minTime = 0;

    queue<Node*>bfsHelper;

    bool answerHelper = treeBurner(root, target, bfsHelper, minTime);

    while (!bfsHelper.empty()) {
        int size = bfsHelper.size();
        minTime++;

        for (int i = 0; i < size; i++) {
            Node* burnNode = bfsHelper.front();
            bfsHelper.pop();

            if (burnNode -> left != NULL) {
                bfsHelper.push(burnNode -> left);
            }

            if (burnNode -> right != NULL) {
                bfsHelper.push(burnNode -> right);
            }
        }
    }

    return minTime;
}