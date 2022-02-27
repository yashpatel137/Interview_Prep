int getNthFromLast(Node *head, int n)
{
    if(head==NULL)
    {
        return -1;
    }
    int count=0;
    Node *temp=head;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    int pos=count-n;
    if(n>count)
    {
        return -1;
    }
    temp=head;
    while(pos--)
    {
        temp=temp->next;
    }
    return temp->data;
}