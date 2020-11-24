/*

Complexity analysis :-

Time complexity : O(1). Since we only have to perform two operation it will cost constant time.

Space complexity : O(1). No extra Space required.

*/


/*

Intution :-

Key idea here his we will copy the content of next Node in our current node and eliminate that next node.

*/


void deleteNode(Node *node)
{
	if (node == NULL) {
		return;
	}

	node -> data = node -> next -> data;
	node -> next = node -> next -> next;
}