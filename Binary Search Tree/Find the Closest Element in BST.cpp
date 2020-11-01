/*

Method : Using BST property and recursion  :                                Verdict : Accepted

Complexity Analysis:

Time complexity : O(H) where H is height of given Binary Search Tree.

Space Complexity : O(H) where H is height of given Binary Search Tree.

*/


/*

Intution Behind efficient solution :-

1) If target value K is present in given BST, then it’s the node having minimum absolute difference.
2) If target value K is less than the value of current node then move to the left child.
3) If target value K is greater than the value of current node then move to the right child.

*/

int minDiff(Node *root, int K)
{
    if (root == NULL) {
        return INT_MAX;
    }

    if (root -> data == K) {
        return 0;
    }

    if (K > root -> data) {
        return min(abs(K - root -> data), minDiff(root -> right, K));
    }

    return min(abs(K - root -> data), minDiff(root -> left, K));
}
