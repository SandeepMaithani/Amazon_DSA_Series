/*

Complexity Analysis :-

Time Complexity: O(N * M). After each cell of N * M DP cell is filled function call will take unique time so overall time
complexity will be O(N * M) to fill the dp matrix.

Space Complexity : O(N * M). Space complexity will be O(N * M) which will be taken be dp matrix.

*/


/*

Intution :-

Case 1: The character is ‘*’ Here two cases arise

  a). We can ignore ‘*’ character and move to next character in the Pattern.
  b). ‘*’ character matches with one or more characters in Text. Here we will move to next character in the string.

Case 2: The character is ‘?’

  We can ignore current character in Text and move to next character in the Pattern and Text.

Case 3: The character is not a wildcard character

  If current character in Text matches with current character in Pattern, we move to next character in the Pattern and Text.
  If they do not match, wildcard pattern and Text do not match.

We can use Dynamic Programming to solve this problem –
  Let dp[i][j] is true if first i characters in given string matches the first j characters of pattern.

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