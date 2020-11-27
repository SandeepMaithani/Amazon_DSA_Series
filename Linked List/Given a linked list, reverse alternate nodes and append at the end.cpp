/*

Complexity analysis :-

Time complexity : O(N). Where N is the No of Nodes in the Linked list, and we will any node atmost twice.

Space complexity : O(1). We will use constant space to maintain even and odd list.

*/


/*

Intution :-

1. The idea is to maintain two linked lists, one list of all odd positioned nodes and other list of all even positioned nodes .

2. Reverse the Linked list with even positioned nodes.

3. Append the reversed list to the end of Linked List with odd positioned nodes.


*/


Node* reverseHelper(Node *head) {
	if (head == NULL) {
		return head;
	}

	Node *prev = NULL;
	Node *mover = head;

	while (mover != NULL) {
		Node *next = mover -> next;
		mover -> next = prev;
		prev = mover;

		mover = next;
	}

	return prev;
}


void rearrange(struct Node *odd)
{

	if (odd == NULL || odd -> next == NULL || odd -> next -> next == NULL) {
		return;
	}

	Node *mover = odd;
	int numInfo = 1;

	Node *oddList = new Node(-1);
	Node *oddHelper = oddList;

	Node *evenList = new Node(-1);
	Node *evenHelper = evenList;

	while (mover != NULL) {
		if (numInfo % 2 == 0) {
			evenHelper -> next = mover;
			evenHelper = evenHelper -> next;
		}
		else {
			oddHelper -> next = mover;
			oddHelper = oddHelper -> next;
		}

		mover = mover -> next;
		numInfo++;
	}

	evenHelper -> next = NULL;

	evenList -> next = reverseHelper(evenList -> next);
	oddHelper -> next = evenList -> next;
}