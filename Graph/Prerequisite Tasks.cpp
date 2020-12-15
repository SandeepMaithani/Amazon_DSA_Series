/*

Complexity Analysis :-

Time Complexity: O(V + E). Time Complexity of our method is same as time complexity of DFS traversal which is O(V+E).

Space Complexity: O(V + E). Since we are considering all tasks as a node so we will need extra space to create a graph of tasks which will cost O(V + E) Memory.


Note :- Here V will be total number of tasks given and E will be total number of prerequisite pairs

*/


/*

Intution :-

Key idea here is we can consider this problem as a graph (related to topological sorting) problem. All tasks are nodes
of the graph and if task u is a prerequisite of task v, we will add a directed edge from node u to node v. Now,
this problem is equivalent to detecting a cycle in the graph represented by prerequisites. If there is a cycle in the
graph, then it is not possible to finish all tasks (because in that case there is no topological order of tasks).

*/

bool isCyclic(int src, vector<vector<int>>&graph, vector<bool>&visited, vector<bool>&ancestor) {

    visited[src] = true;
    ancestor[src] = true;

    for (auto neighbour : graph[src]) {
        if (!visited[neighbour]) {
            if (isCyclic(neighbour, graph, visited, ancestor)) {
                return true;
            }
        }
        else if (ancestor[neighbour]) {
            return true;
        }
    }

    ancestor[src] = false;

    return false;
}

bool canFinish(int numTasks, vector<pair<int, int> >& prerequisites) {
    if (numTasks == 1) {
        return true;
    }

    vector<vector<int>>graph(numTasks);

    for (int i = 0; i < prerequisites.size(); i++) {
        int src = prerequisites[i].first;
        int dst = prerequisites[i].second;

        graph[src].push_back(dst);
    }

    vector<bool>visited(numTasks, false);
    vector<bool>ancestor(numTasks, false);

    for (int i = 0; i < numTasks; i++) {
        if (!visited[i]) {
            if (isCyclic(i, graph, visited, ancestor)) {
                return false;
            }
        }
    }

    return true;
}