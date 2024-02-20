struct ListNode* reverseList(struct ListNode* head) { struct
ListNode *prevNode, *currentNode, *nextNode; prevNode = NULL;
currentNode = head; while (currentNode != NULL) {
nextNode = currentNode->next; currentNode->next = prevNode;
prevNode = currentNode; currentNode = nextNode;
} head = prevNode;
return head;
}
