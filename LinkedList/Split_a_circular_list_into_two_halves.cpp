void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *slow=head,*fast=head->next;
    while(fast!=head && fast->next!=head)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    *head1_ref=head;
    *head2_ref=slow->next;
    slow->next=head;
    Node *temp=*head2_ref;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=*head2_ref;
}