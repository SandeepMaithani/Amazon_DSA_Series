/*

Complexity Analysis:

Time complexity : O(N), Where N is no of nodes in the binary tree we will process each node once.

Space Complexity : O(H), Where H is height of the binary tree and calling stack will used O(H) memory.

*/



/*

Intution :-

If we are at leaf node then just return its value because it can’t be ancestor of any node. Then at each internal node we will try to get minimum value from left subtree and right subtree and calculate the difference between node value and this minimum value and according to that we will update the result.
As we are calculating minimum value while retuning in recurrence we will check minimum value which may be from left child , right child or root node itself and return the minimum value.

*/


int getMinChild(Node* root, int& answer) {
    if (root == NULL) {
        return INT_MAX;
    }

    if (root -> left == NULL && root -> right == NULL) {
        return root -> data;
    }

    int leftMin = getMinChild(root -> left, answer);
    int rightMin = getMinChild(root -> right, answer);

    int minChild = min(leftMin, rightMin);

    answer = max(answer, (root -> data) - minChild);

    return min(root -> data, minChild);
}

int maxDiff(Node* root)
{
    int answer = INT_MIN;

    int temp = getMinChild(root, answer);

    return answer;
}