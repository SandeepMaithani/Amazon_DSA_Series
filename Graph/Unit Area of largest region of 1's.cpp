/*

Complexity Analysis :-

Time Complexity: O(ROW * COL). At worst case all the cells will be visited so time complexity is O(ROW * COL).

Space Complexity: O(ROW * COL). To store the visited nodes O(ROW * COL) space is needed.

*/


/*

Intution :-

A cell in 2D matrix can be connected to at most 8 neighbours.So in DFS, make recursive calls for 8 neighbours of
that cell.Keep a visited matrix/HashMap to keep track of all visited cells.Also keep track of the visited 1’s in
every DFS that will be length of that particular region and update maximum length region.

*/


void componentHelper(int row, int col, int A[SIZE][SIZE], int N, int M, vector<vector<bool>>&visited, int &localArea) {
    if (row < 0 || col < 0 || row >= N || col >= M || A[row][col] == 0 || visited[row][col] == true) {
        return;
    }

    localArea++;
    visited[row][col] = true;

    componentHelper(row, col + 1, A, N, M, visited, localArea);
    componentHelper(row, col - 1, A, N, M, visited, localArea);
    componentHelper(row - 1, col, A, N, M, visited, localArea);
    componentHelper(row - 1, col - 1, A, N, M, visited, localArea);
    componentHelper(row - 1, col + 1, A, N, M, visited, localArea);
    componentHelper(row + 1, col, A, N, M, visited, localArea);
    componentHelper(row + 1, col - 1, A, N, M, visited, localArea);
    componentHelper(row + 1, col + 1, A, N, M, visited, localArea);

}

int findMaxArea(int N, int M, int A[SIZE][SIZE] )
{
    int maxArea = 0;
    vector<vector<bool>>visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == false && A[i][j] == 1) {
                int localArea = 0;
                componentHelper(i, j, A, N, M, visited, localArea);
                if (maxArea < localArea) {
                    maxArea = localArea;
                }
            }
        }
    }

    return maxArea;
}