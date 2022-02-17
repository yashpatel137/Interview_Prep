Node *removeDuplicates(Node *head)
{
    Node *cur=head,*tempnext;
    if(cur==NULL)
    {
        return NULL;
    }
    while(cur->next!=NULL)
    {
        if(cur->data==cur->next->data)
        {
            tempnext=cur->next->next;
            free(cur->next);
            cur->next=tempnext;
        }
        else
        {
            cur=cur->next;
        }
    }
    return head;
}