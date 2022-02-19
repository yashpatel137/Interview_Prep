Node* findIntersection(Node* head1, Node* head2)
{
    Node *ptr1=head1,*ptr2=head2;
    Node *head=NULL,*curr=NULL;
    while(ptr1 && ptr2)
    {
        if(ptr1->data == ptr2->data)
        {
            if(head==NULL)
            {
                Node *temp=new Node(ptr1->data);
                head=temp;
                curr=temp;
            }
            else
            {
                Node *temp=new Node(ptr1->data);
                curr->next=temp;
                curr=curr->next;
            }
            ptr2=ptr2->next;
            ptr1=ptr1->next;
        }
        else
        {
            if(ptr1->data>ptr2->data)
            {
                ptr2=ptr2->next;
            }
            else
            {
                ptr1=ptr1->next;
            }
        }
    }
    return head;
}