/*

Method 1 : using Help of iterative Inorder  :                      Verdict : Accepted

Complexity Analysis:

Time complexity : O(M + N), where M and N are no of nodes in the tree.

Space Complexity : O(H1+H2), where H1 is Height of BST1 and H2 is Height of BST2.

*/


class Solution {
public:
    void inOrderHelper(TreeNode* root, stack<TreeNode*>& st) {
        while (root != NULL) {
            st.push(root);
            root = root -> left;
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>mergeTree;
        stack<TreeNode*> st1, st2;

        inOrderHelper(root1, st1);
        inOrderHelper(root2, st2);

        while (!st1.empty() && !st2.empty()) {
            TreeNode* firstTreeNode = st1.top();
            TreeNode* secondTreeNode = st2.top();

            if (firstTreeNode -> val <= secondTreeNode -> val) {
                mergeTree.push_back(firstTreeNode -> val);
                st1.pop();
                inOrderHelper(firstTreeNode -> right, st1);
            }
            else {
                mergeTree.push_back(secondTreeNode -> val);
                st2.pop();
                inOrderHelper(secondTreeNode -> right, st2);
            }
        }

        while (!st1.empty()) {

            TreeNode* firstTreeNode = st1.top();

            mergeTree.push_back(firstTreeNode -> val);
            st1.pop();
            inOrderHelper(firstTreeNode -> right, st1);
        }

        while (!st2.empty()) {

            TreeNode* secondTreeNode = st2.top();

            mergeTree.push_back(secondTreeNode -> val);
            st2.pop();
            inOrderHelper(secondTreeNode -> right, st2);
        }

        return mergeTree;

    }
};


/*

Method 2 : extracting values in vector and then merge  :                          Verdict : Accepted

Complexity Analysis:

Time complexity : O(M + N), where M and N are no of nodes in the tree.

Space Complexity : O(M+N), we need extra space to store values after inorder traversal.

*/


void inOrderHelper(Node *root, vector<int>& keeper) {
    if (root == NULL) {
        return;
    }

    inOrderHelper(root -> left, keeper);
    keeper.push_back(root -> data);
    inOrderHelper(root -> right, keeper);
}

void mergeTwoKeeper(vector<int>& keeper1, vector<int>& keeper2, vector<int>& finalKeeper) {
    int i = 0, j = 0;
    while ( i < keeper1.size() && j < keeper2.size()) {
        if (keeper1[i] < keeper2[j]) {
            finalKeeper.push_back(keeper1[i]);
            i++;
        }
        else {
            finalKeeper.push_back(keeper2[j]);
            j++;
        }
    }

    while (i < keeper1.size()) {
        finalKeeper.push_back(keeper1[i]);
        i++;
    }

    while (j < keeper2.size()) {
        finalKeeper.push_back(keeper2[j]);
        j++;
    }
}

vector<int> merge(Node *root1, Node *root2)
{
    vector<int> keeper1, keeper2, finalKeeper;

    inOrderHelper(root1, keeper1);
    inOrderHelper(root2, keeper2);
    mergeTwoKeeper(keeper1, keeper2, finalKeeper);

    return finalKeeper;
}