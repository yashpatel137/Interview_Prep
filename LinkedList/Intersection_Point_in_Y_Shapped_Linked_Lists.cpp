int intersectPoint(Node* head1, Node* head2)
{
    Node *ptr1=head1,*ptr2=head2;
    int n1=0,n2=0;
    while(ptr1)
    {
        n1++;
        ptr1=ptr1->next;
    }
    while(ptr2)
    {
        n2++;
        ptr2=ptr2->next;
    }
    ptr1=head1;
    ptr2=head2;
    if(n1>n2)
    {
        int dif=n1-n2;
        while(dif--)
        {
            ptr1=ptr1->next;
        }
    }
    else
    {
        int dif=n2-n1;
        while(dif--)
        {
            ptr2=ptr2->next;
        }
    }
    while(ptr1 && ptr2)
    {
        if(ptr1==ptr2)
        {
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}