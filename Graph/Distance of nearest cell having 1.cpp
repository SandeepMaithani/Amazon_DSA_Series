/*

Complexity Analysis :-

Time Complexity: O(N*M). In BFS traversal every element is traversed only once so time Complexity is O(N*M).

Space Complexity: O(N*M). To store every element in the matrix O(N*M) space is required.

*/


/*

Intution :-

Key idea here is first we will find out all the cell which have nearest 1 at the distance of 1 unit similarly for 2 unit
and so on for this we will start doing BFS from every occurance of 1 in the matrix and check if its adjacent cell of current
matrix can get better solution from current cell if yes we will update the distance and check whether these adjacent cell
and get better answer for their adjacent cell by pushing them in bfs queue so by this we first get distance of all cell with
distance 0 then cell with distance 1 and so on.

*/


void cellHelper(int curRow, int curCol, int adjRow, int adjCol, int N, int M, vector<vector<int>>&distance, queue<pair<int, int>>&bfsHelper) {
	if (adjRow < 0 || adjRow >= N || adjCol < 0 || adjCol >= M) {
		return;
	}

	if (distance[adjRow][adjCol] > distance[curRow][curCol] + 1) {
		distance[adjRow][adjCol] = distance[curRow][curCol] + 1;
		bfsHelper.push({adjRow, adjCol});
	}
}

vector <vector <int> > nearest(vector<vector<int>> &mat, int N, int M) {
	vector<vector<int>>distance(N, vector<int>(M, INT_MAX));

	queue<pair<int, int>>bfsHelper;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (mat[i][j] == 1) {
				distance[i][j] = 0;
				bfsHelper.push({i, j});
			}
		}
	}

	while (!bfsHelper.empty()) {
		int curRow = bfsHelper.front().first;
		int curCol = bfsHelper.front().second;

		bfsHelper.pop();

		cellHelper(curRow, curCol, curRow, curCol + 1, N, M, distance, bfsHelper);
		cellHelper(curRow, curCol, curRow, curCol - 1, N, M, distance, bfsHelper);
		cellHelper(curRow, curCol, curRow - 1, curCol, N, M, distance, bfsHelper);
		cellHelper(curRow, curCol, curRow + 1, curCol, N, M, distance, bfsHelper);
	}

	return distance;
}