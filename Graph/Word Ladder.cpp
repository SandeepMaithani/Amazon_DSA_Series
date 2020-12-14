/*

Complexity Analysis :-

Time Complexity: O(N*N*M), Where M is the number of entries originally in the dictionary and N is the size of the string.

Space Complexity: O(M*N), Where M are the strings are stored in queue, So the space Complexity is O(M*N).

*/



/*

Intution :- Key idea here is to use BFS. We will Start from the given start word. Push the word in the queue Run a
loop until the queue is empty, Traverse all words that adjacent (differ by one character) to it and push the word in
a queue (for BFS) Keep doing so until we find the target word or we have traversed all words.

*/


int WordLadderLength(string beginWord, string endWord, set<string>& D)
{
    unordered_set<string>hashSet;

    for (auto word : D) {
        hashSet.insert(word);
    }

    if (hashSet.find(endWord) == hashSet.end()) {
        return 0;
    }

    queue<string>bfsHelper;
    bfsHelper.push(beginWord);

    int changeCount = 0;

    while (!bfsHelper.empty()) {
        int size = bfsHelper.size();
        changeCount++;

        for (int i = 0; i < size; i++) {
            string currWord = bfsHelper.front();
            bfsHelper.pop();

            for (int j = 0; j < currWord.length(); j++) {
                string newWord = currWord;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    newWord[j] = ch;

                    if (newWord == currWord) {
                        continue;
                    }

                    if (newWord == endWord) {
                        return changeCount + 1;
                    }

                    if (hashSet.find(newWord) != hashSet.end()) {
                        bfsHelper.push(newWord);
                        hashSet.erase(newWord);
                    }
                }
            }
        }
    }

    return 0;

}