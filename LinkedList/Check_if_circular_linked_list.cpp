bool isCircular(Node *head)
{
    if(head==NULL)
    {
        return true;
    }
    Node *temp=head->next;
    while(temp!=NULL && temp!=head)
    {
        temp=temp->next;
    }
    return (temp==head);
}