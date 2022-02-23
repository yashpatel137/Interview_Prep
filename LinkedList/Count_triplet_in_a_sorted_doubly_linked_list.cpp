int countPairs(Node *first,Node *sec,int value)
{
    int count=0;
    while(first!=NULL && sec!=NULL && first!=sec && sec->next!=first)
    {
        if((first->data + sec->data)==value)
        {
            count++;
            first=first->next;
            sec=sec->prev;
        }
        else if((first->data + sec->data)>value)
        {
            sec=sec->prev;
        }
        else
        {
            first=first->next;
        }
    }
    return count;
}

int countTriplet(Node *head, int x)
{
    if(head==NULL)
    {
        return 0;
    }
    Node *curr,*first,*last;
    int count=0;
    last=head;
    while(last->next!=NULL)
    {
        last=last->next;
    }
    for(curr=head;curr!=NULL;curr=curr->next)
    {
        first=curr->next;
        count+=countPairs(first,last,x-curr->data);
    }
    return count;
}