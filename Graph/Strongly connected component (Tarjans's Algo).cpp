/*

Complexity Analysis :-

Time Complexity : O(V+E). Time Complexity: The above algorithm mainly calls DFS, DFS takes O(V+E) for a graph represented using adjacency list.

Space Complexity : O(V). We need extra memory for the stack and visited vector etc which will cost at most O(V) memory each.

*/


void dfsHelper(int src, vector<int> adj[], int N, int &curTime, stack<int>&helperStack, vector<bool>&isActive, vector<bool>&visited, vector<int>&discoveryTime, vector<int>&minAncestor) {
	if (visited[src] == true) {
		return;
	}

	curTime++;

	discoveryTime[src] = minAncestor[src] = curTime;
	helperStack.push(src);
	isActive[src] = true;
	visited[src] = true;

	for (auto neighbour : adj[src]) {
		if (visited[neighbour] == false) {
			dfsHelper(neighbour, adj, N, curTime, helperStack, isActive, visited, discoveryTime, minAncestor);
			minAncestor[src] = min(minAncestor[src],  minAncestor[neighbour]);
		}
		else if (isActive[neighbour]) {
			minAncestor[src] = min(minAncestor[src],  discoveryTime[neighbour]);
		}
	}

	if (discoveryTime[src] == minAncestor[src]) {
		while (helperStack.top() != src) {
			cout << helperStack.top() << " ";
			isActive[helperStack.top()] = false;
			helperStack.pop();
		}

		cout << helperStack.top() << ",";
		isActive[helperStack.top()] = false;
		helperStack.pop();
	}
}

void find(vector<int> adj[], int N) {
	stack<int>helperStack;
	vector<bool>isActive(N, false);
	vector<bool>visited(N, false);
	vector<int>discoveryTime(N);
	vector<int>minAncestor(N);

	int curTime = 0;

	for (int i = 0; i < N; i++) {
		if (visited[i] == false) {
			dfsHelper(i, adj, N, curTime, helperStack, isActive, visited, discoveryTime, minAncestor);
		}
	}
}