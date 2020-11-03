/*

Method 1 : Recursion + Memoization                              Verdict : Accepted

Complexity Analysis:

Time complexity : O(N*N), .

Space Complexity : O(N), we need extra space to store values after inorder traversal.

*/



/*

Method 2 : Recursive Solution                            Verdict : TLE

Complexity Analysis:

Time complexity : O(N!), where N is no of nodes in the tree.

Space Complexity : O(1), No extra space required.

*/


int numTrees(int N) {
	if (N <= 1) {
		return 1;
	}

	int countStructure = 0;

	for (int i = 1; i <= N; i++) {
		countStructure += (numTrees(i - 1) * numTrees(N - i));
	}

	return countStructure;
}