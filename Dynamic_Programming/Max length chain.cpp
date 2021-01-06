/*

Complexity analysis :-

Time Complexity : O(N*N). where n is the number of pairs.

Space Complexity : O(N). Space required by dp array.

*/


/*

Intution:-

Key idea here is that this problem is a variation of standard Longest Increasing Subsequence problem. Following is a simple two step process.

  1) Sort given pairs in increasing order of first (or smaller) element. Why do not need sorting? Consider the example {{6, 8}, {3, 4}}
     to understand the need of sorting. If we proceed to second step without sorting, we get output as 1. But the correct output is 2.

  2) Now run a modified LIS process where we compare the second element of already finalized LIS with the first element of new LIS being constructed.

*/


bool compare(struct val a, struct val b) {
    return a.first < b.first;
}

int maxChainLen(struct val p[], int n)
{
    sort(p, p + n, compare);

    vector<int>dp(n);

    int globalMax = 0;

    for (int i = 0; i < n; i++) {

        int localMax = 0;

        for (int j = 0; j < i; j++) {
            if (p[j].second < p[i].first && localMax < dp[j]) {
                localMax = dp[j];
            }
        }

        dp[i] = localMax + 1;

        globalMax = max(dp[i], globalMax);
    }

    return globalMax;
}