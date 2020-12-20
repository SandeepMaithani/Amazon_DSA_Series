/*

Method 1 :- using Set for implementation of Dijkstra algo                   Verdict :- Accepted

Complexity Analysis :-

Time Complexity : O(N * N * log N). We will be doing a total of N*N insertion and atmost N element will be there in Set at any point of time.

Space Complexity : O(N*N). We need extra memory for the set and distance matrix which will cost O(N*N) memory.

*/


/*

Note :- It is not possible to solve this problem using dynamic programming similar to minimum cost problem (where right and down move are allowed)
because here current state depends not only on right and bottom cells but also on left and upper cells.

Intution :-

Key idea here is to solve this problem using dijkstra’s algorithm. We will find the shortest path from source to target in term of cost, Each cell
of grid represents a vertex and neighbor cells adjacent vertices. We do not make an explicit graph from these cells instead we will use matrix as it is
in our dijkstra’s algorithm and maintain a distance matrix seprately and update the shortest cost(distance) from source to each node(cell) in that matrix.


*/

bool isSafe(int x, int y, int n) {
    if (x < 0 || y < 0 || x >= n || y >= n) {
        return false;
    }

    return true;
}

int shortest(vector<vector<int> > &grid, int n) {

    int distance[1001][1001];

    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            distance[i][j] = INT_MAX;
        }
    }

    set<pair<int, pair<int, int>>>hashSet;

    distance[0][0] = grid[0][0];
    hashSet.insert({distance[0][0], {0, 0}});

    int dx[] = {0, 0, -1, 1};
    int dy[] = { -1, 1, 0, 0};

    while (!hashSet.empty()) {
        pair<int, pair<int, int>> curVertex = *(hashSet.begin());
        int curCost = curVertex.first;
        int x = curVertex.second.first;
        int y = curVertex.second.second;

        hashSet.erase(hashSet.begin());

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isSafe(newX, newY, n) && (distance[newX][newY] > curCost + grid[newX][newY])) {
                distance[newX][newY] = curCost + grid[newX][newY];
                hashSet.insert({distance[newX][newY], {newX, newY}});
            }
        }

    }

    return distance[n - 1][n - 1];
}



/*

Method 2 :- using minHeap for implementation of Dijkstra algo                   Verdict :- TLE

Complexity Analysis :-

Time Complexity : O(N * N * log N). We will be doing a total of N*N insertion and atmost N element will be there in min heap at any point of time.

Space Complexity : O(N*N). We need extra memory for the visited array and min heap which will cost O(N*N) memory.

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