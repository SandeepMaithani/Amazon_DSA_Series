/*

Method 1 : using priority queue                              Verdict : Accepted

Complexity Analysis:

Time complexity : O(N*log(k)) where k is the number of linked lists.

The comparison cost will be reduced to O(log(k)) for every pop and insertion to priority queue. But finding the node
with the smallest value just costs O(1) time.There are N nodes in the final linked list.

Space complexity : O(k) The code above present applies in-place method which cost O(1) space. And the priority queue
(often implemented with heaps) costs O(k) space (it's far less than N in most situations).

*/


/*

Intution :-

Key idea here is we will store first node of all the linked list in a min heap and then merge the minimum element from heap
to the merge list and put the next node of selected list in the min Heap by this we will have atmost K element at any
point of time in our min heap and we will merge list simultaneously.


*/


class Solution {
public:
    ListNode* mergeHelper(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>minHeap;
        ListNode* dummy = new ListNode(-1);
        ListNode* merger = dummy;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                minHeap.push({lists[i] -> val, lists[i]});
            }
        }

        while (minHeap.size() != 0) {
            pair<int , ListNode*>currNode = minHeap.top();
            minHeap.pop();

            merger -> next = currNode.second;
            merger = merger -> next;

            ListNode* nextNode = currNode.second -> next;

            if (nextNode != NULL) {
                minHeap.push({nextNode -> val, nextNode});
            }
        }

        return dummy -> next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        if (lists.size() == 1) {
            return lists[0];
        }

        return mergeHelper(lists);

    }
};



/*

Method 2 : using merge two linked List                            Verdict : Accepted

Complexity Analysis:

Time complexity : O(N^2), where N is total number of nodes, i.e., N = kn.

Space Complexity : O(1), As no extra space is required.

*/


/*

Intution :-

Key idea here is we will pick all the linked list one by one and merge them with the so formed resulted merge list
after merging all the linked list with the method of merge two linked list we will get the final merged linked list.

*/


Node* mergeTwoList(Node* head1, Node* head2) {
    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    Node* dummy = new Node(0);
    Node* merger = dummy;

    while (head1 != NULL && head2 != NULL) {

        if (head1 -> data <= head2 -> data) {
            merger -> next = head1;
            head1 = head1 -> next;
        }
        else {
            merger -> next = head2;
            head2 = head2 -> next;
        }

        merger = merger -> next;
    }

    while (head1 != NULL) {
        merger -> next = head1;
        head1 = head1 -> next;
        merger = merger -> next;
    }

    while (head2 != NULL) {
        merger -> next = head2;
        head2 = head2 -> next;
        merger = merger -> next;
    }

    return dummy -> next;
}

Node * mergeKLists(Node *arr[], int N)
{
    if (N == 0) {
        return NULL;
    }

    if (N == 1) {
        return arr[0];
    }

    Node * mergeList = mergeTwoList(arr[0], arr[1]);

    for (int i = 2; i < N; i++) {
        mergeList = mergeTwoList(arr[i], mergeList);
    }

    return mergeList;
}