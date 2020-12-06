/*

Method 2 : Using Priority Queue(Min Heap)                           Verdict : Accepted

Complexity Analysis :-

Time Complexity: O(N*log(N)). min heap take log(N) time to insert elements and total of N elements are there which will cost N*Log(N) time.

Space Complexity: O(N). We need O(N) extra memory each for min heap and hashmap.

*/


/*

Intution :-

Key idea here is we will store all the element in a min heap to get minimum element each time and also maintain
a hashMap to keep track of element and their current index so now we will start checking from start index 0 and
each time we will extract minimum element from min heap if min element is at it right place then we will continue
otherwise we will swap the min element with the element at its right position and update the element index in
hashMap as well.

*/

int minSwaps(int arr[], int N) {
    if (N == 1) {
        return 0;
    }
    if (N == 2 && arr[0] < arr[1]) {
        return 1;
    }

    int swapCount = 0;

    priority_queue<int, vector<int>, greater<int>>minHeap;
    unordered_map<int, int>hashMap;

    for (int i = 0; i < N; i++) {
        minHeap.push(arr[i]);
        hashMap[arr[i]] = i;
    }

    int pos = 0;

    while (!minHeap.empty()) {
        int curr = minHeap.top();
        int minInd = hashMap[curr];
        minHeap.pop();

        if (curr != arr[pos]) {
            hashMap[arr[pos]] = minInd;
            swap(arr[pos], arr[minInd]);
            swapCount++;
        }
        pos++;
    }

    return swapCount;
}


/*

Method 3 : Using selection Sort                           Verdict : TLE

Complexity Analysis :-

Time Complexity: O(N^2). Since we are performing a linear search for every element to find minimum element index in the array from current element index which will cost O(N) time for search ans overall time will be O(N*N).

Space Complexity: O(1). We don't require extra space.

*/



/*

Intution :-

Key idea behind this brute force solution is we will start from 0th index and look for minimum element in subsequent array if the minimum element exist which is also less then our current element then we will swap current element with minimum element and increment the swap counter similarly we will do this for every element to get our minimum swap count.

*/


int minSwaps(int arr[], int N) {
    if (N == 1) {
        return 0;
    }
    if (N == 2 && arr[0] < arr[1]) {
        return 1;
    }

    int swapCount = 0;

    for (int i = 0; i < N - 1; i++) {
        int swapInd = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[swapInd] > arr[j]) {
                swapInd = j;
            }
        }

        if (swapInd != i) {
            swap(arr[swapInd], arr[i]);
            swapCount++;
        }
    }

    return swapCount;
}