
/*

Method 2 :- using minHeap implementation Dijkstra algo                   Verdict :- TLE

Complexity Analysis :-

Time Complexity : O(N * N * log N). We will be doing a total of N*N insertion and atmost N element will be there in min heap at any point of time.

Space Complexity : O(N*N). We need extra memory for the visited array and min heap which will cost O(V) memory.

*/



bool isSafe(int x, int y, int n) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    }

    return true;
}

int shortest(vector<vector<int> > &grid, int n) {
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    vector<vector<int>>distance(n, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>minHeap;

    distance[0][0] = grid[0][0];
    minHeap.push({distance[0][0], {0, 0}});

    int dx[] = {0, 0, -1, 1};
    int dy[] = { -1, 1, 0, 0};

    while (!minHeap.empty()) {
        int curCost = minHeap.top().first;
        int x = minHeap.top().second.first;
        int y = minHeap.top().second.second;

        minHeap.pop();

        if (visited[x][y] == true) {
            continue;
        }

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isSafe(newX, newY, n)) {
                if (visited[newX][newY] == false && distance[newX][newY] > curCost + grid[newX][newY]) {
                    distance[newX][newY] = curCost + grid[newX][newY];
                    minHeap.push({distance[newX][newY], {newX, newY}});
                }
            }
        }

    }

    return distance[n - 1][n - 1];
}