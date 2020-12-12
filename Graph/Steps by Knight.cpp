/*

Complexity Analysis :-

Time Complexity: O(N*N). At worst case, all the cells will be visited so time complexity is O(N*N).

Space Complexity: O(N*N). We will be using a Queue, visited matrix and distance matrix which whill require O(N*N) space.

*/


/*

Intution :-

The Key idea here is this problem can be seen as shortest path in unweighted graph. Therefore we will use BFS to solve this problem. We will try all 8 possible positions where a Knight can reach from its current position. If reachable position is not already visited and is inside the board, we will push that reachable position into queue with distance 1 more than its parent state. Finally we return distance of target position, when it gets pop out from queue.

*/



bool isValid(int row, int col, int N) {
    if (row < 1 || row > N || col < 1 || col > N) {            // because we have 1 based indexing here
        return false;
    }

    return true;
}


int minStepToReachTarget(int knightPos[], int targetPos[], int N) {
    int srcRow = knightPos[0], srcCol = knightPos[1], tarRow = targetPos[0], tarCol = targetPos[1];

    if (srcRow == tarRow && srcCol == tarCol) {
        return 0;
    }

    int moveRow[] = { -2, -1, 1, 2, 2, 1, -1, -2};
    int moveCol[] = {1, 2, 2, 1, -1, -2, -2, -1};

    vector<vector<bool>>visited(N + 1, vector<bool>(N + 1, false));
    vector<vector<int>>distance(N + 1, vector<int>(N + 1));
    queue<pair<int, int>>bfsHelper;

    distance[srcRow][srcCol] = 0;
    bfsHelper.push({srcRow, srcCol});

    while (!bfsHelper.empty()) {
        int curRow = bfsHelper.front().first;
        int curCol = bfsHelper.front().second;
        bfsHelper.pop();

        if (curRow == tarRow && curCol == tarCol) {
            return distance[curRow][curCol];
        }

        if (visited[curRow][curCol]) {
            continue;
        }

        visited[curRow][curCol] = true;

        for (int i = 0; i < 8; i++) {
            int adjRow = curRow + moveRow[i];
            int adjCol = curCol + moveCol[i];

            if (isValid(adjRow, adjCol, N) && visited[adjRow][adjCol] == false) {
                distance[adjRow][adjCol] = distance[curRow][curCol] + 1;
                bfsHelper.push({adjRow, adjCol});
            }
        }
    }

    return -1;  // Incase if it is not possible to reach the target position from source position
}