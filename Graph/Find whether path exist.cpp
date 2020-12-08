/*

Complexity Analysis :-

Time Complexity: O(N*N). Every cell of the matrix is visited only once so the time complexity is O(N*N).

Space Complexity: O(N*N). Space is required to store the visited array.

*/


/*

Intution :-

Key idea here is to use Depth-First Search(DFS). Consider each cell as a node and each boundary between any two adjacent cells be an edge. so the total number of Node is N * N.
So the idea is to do a Depth-first search from the starting cell till the ending cell is found.

*/


void pathHelper(vector<vector<int>>&M, vector<vector<bool>>&visited, int N, int row, int col, bool &pathExist) {
    if (row < 0 || col < 0 || row >= N || col >= N || M[row][col] == 0 || visited[row][col] || pathExist) {
        return;
    }

    visited[row][col] = true;

    if (M[row][col] == 2) {
        pathExist = true;
        return;
    }

    pathHelper(M, visited, N, row  + 1, col, pathExist);
    pathHelper(M, visited, N, row - 1, col, pathExist);
    pathHelper(M, visited, N, row, col + 1, pathExist);
    pathHelper(M, visited, N, row, col - 1, pathExist);
}

bool is_possible(vector <vector <int>> &M, int N) {
    int sourceRow, sourceCol;
    bool pathExist = false;

    vector<vector<bool>>visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (M[i][j] == 1) {
                sourceRow = i;
                sourceCol = j;
            }
        }
    }

    pathHelper(M, visited, N, sourceRow, sourceCol, pathExist);

    return pathExist;
}