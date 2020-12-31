/*

Complexity Analysis :-

Time Complexity: O(N * M).

Space Complexity : O(N * M).

*/

bool LCS(string &pattern, string &word, vector<vector<int>>&dp, int n, int m) {

	if (n <= 0 && m <= 0) {
		return true;
	}

	if (n <= 0) {
		return false;
	}

	if (m <= 0) {
		if (pattern[n - 1] == '*') {
			return dp[n][m] = LCS(pattern, word, dp, n - 1, m);
		}
		else {
			return false;
		}
	}

	if (dp[n][m] != -1) {
		return dp[n][m];
	}

	if ((pattern[n - 1] == word[m - 1]) || (pattern[n - 1] == '?')) {
		return dp[n][m] = LCS(pattern, word, dp, n - 1, m - 1);
	}
	else if (pattern[n - 1] == '*') {
		bool first = LCS(pattern, word, dp, n - 1, m);
		bool second = LCS(pattern, word, dp, n, m - 1);

		return dp[n][m] = first || second;
	}
	else {
		return dp[n][m] = false;
	}
}


int wildCard(string pattern, string str)
{
	int n = pattern.length();
	int m = str.length();

	vector<vector<int>>dp(n + 1, vector<int>(m + 1, -1));

	bool answer = LCS(pattern, str, dp, n, m);

	return answer;
}