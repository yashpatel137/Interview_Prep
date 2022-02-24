Node* reverseDLLInGroups(Node* head, int k)
{	
	if(head == NULL)
	{
		return NULL;
	}
	Node* curr = head, *last = NULL, *ahead;
	int count = k;
	while(curr != NULL and count > 0)
	{
		ahead = curr->next;
		curr->next = last;
		if(last != NULL)
		{
			last->prev = curr;
		}
		last = curr;
		curr = ahead; 
		count -= 1;
	}
	head->next = reverseDLLInGroups(curr, k); 
	return last;
}