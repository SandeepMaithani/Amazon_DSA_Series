/*

Complexity Analysis :-

Time Complexity: O(N + K). Where N is size of dictonary and K is no of alphabet used.

It will cost O(n + K) time to create a graph. The second step is topological sorting.The time complexity of
topological sorting is O(V+E), which is O(N + K) here. So overall time complexity is O(N + K) + O(N + K) which is O(N + K).

Space Complexity : O(K). Where K is no of alphabet used in dictonary.

The extra space is needed for the helper stack , visited vector and to create a graph which will
cost atmost O(K) extra memory.


*/


/*

Intution :-

Key idea here is to create a graph of characters and then find topological sorting of the created graph. Following are the detailed steps.

1) Create a graph g with number of vertices equal to the size of alphabet in the given alien language. For example, if the alphabet size is 5, then there can be 5 characters in words. Initially there are no edges in graph.

2) Do following for every pair of adjacent words in given sorted array.
          a) Let the current pair of words be word1 and word2. One by one compare characters of both words and find the first mismatching characters.
          b) Create an edge in graph from mismatching character of word1 to that of word2.

3) Print topological sorting of the above created graph.

*/


void topoSortHelper(int src, vector<int>graph[], vector<bool>&visited, stack<int>&helperStack) {
    visited[src] = true;

    for (auto neighbour : graph[src]) {
        if (visited[neighbour] == false) {
            topoSortHelper(neighbour, graph, visited, helperStack);
        }
    }

    helperStack.push(src);
}


string findOrder(string dict[], int N, int K) {
    vector<int>graph[K];
    string charOrder = "";

    for (int i = 0; i < N - 1; i++) {
        string firstWord = dict[i];
        string secondWord = dict[i + 1];

        int minLength = min(firstWord.length(), secondWord.length());

        for (int j = 0; j < minLength; j++) {
            if (firstWord[j] != secondWord[j]) {
                int before = firstWord[j] - 'a';
                int after = secondWord[j] - 'a';

                graph[before].push_back(after);
                break;
            }
        }
    }

    stack<int>helperStack;
    vector<bool>visited(K, false);

    for (int i = 0; i < K; i++) {
        if (visited[i] == false) {
            topoSortHelper(i, graph, visited, helperStack);
        }
    }

    while (!helperStack.empty()) {
        char ch = helperStack.top() + 'a';
        charOrder += ch;
        helperStack.pop();
    }

    return charOrder;
}