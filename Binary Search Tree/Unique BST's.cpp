/*

Method 1 : Recursion + Memoization                              Verdict : Accepted

Complexity Analysis:

Time complexity : O(N*N), Since we will consider each node as root node it will require O(N) time to memoize data so O(N*N).

Space Complexity : O(N), we need extra space to store values after inorder traversal.

*/



/*

Intution : -

For a current N, each node 'i' till 'n' can become a root,
and the elements smaller than 'i' are left subtree nodes and greater than 'i' are part of right subtree.
Both left and right subtree nodes then again be arranged amongst themselves

*/


class Solution {
public:
	int numTreesHelper(int N, vector<int>& dp) {

		if (N <= 1) {
			return 1;
		}

		if (dp[N] != -1) {
			return dp[N];
		}

		int countStructure = 0;

		for (int i = 1; i <= N; i++) {

			int leftCount = numTreesHelper(i - 1, dp);
			int rightCount = numTreesHelper(N - i, dp);

			countStructure += leftCount * rightCount;
		}

		return (dp[N] = countStructure);
	}

	int numTrees(int N) {
		vector<int> dp(N + 1, -1);
		return numTreesHelper(N, dp);
	}
};




/*

Method 2 : Recursive Solution                            Verdict : TLE

Complexity Analysis:

Time complexity : O(2^N), where N is no of nodes in the tree.

Space Complexity : O(1), No extra space required.

*/


int numTrees(int N) {
	if (N <= 1) {
		return 1;
	}

	int countStructure = 0;

	for (int i = 1; i <= N; i++) {

		int leftCount = numTrees(i - 1);
		int rightCount = numTrees(N - i);

		countStructure += leftCount * rightCount;
	}

	return countStructure;
}