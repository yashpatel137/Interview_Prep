void deleteNode(Node** head, int key)
{
    if (*head == NULL)
        return;
    if((*head)->data==key && (*head)->next==*head)
    {
        free(*head);
        *head=NULL;
        return;
    }
    Node *last=*head,*d;
    if((*head)->data==key)
    {
        while(last->next!=*head)
            last=last->next;
        last->next=(*head)->next;
        free(*head);
        *head=last->next;
      return;
    }
    while(last->next!=*head&&last->next->data!=key)
    {
        last=last->next;
    }
    if(last->next->data==key)
    {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else
        cout<<"no such keyfound";
}


//Method 2
void deleteNode(struct Node **head, int key)
{
    Node *temp=*head;
    while(temp->next->data!=key)
    {
        temp=temp->next;
    }
    Node *del=temp->next;
    temp->next=temp->next->next;
    delete(del);
}
 void reverse(struct Node** head_ref)
{
    Node *curr=*head_ref,*next,*prev=NULL;
    while(curr->next!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    curr->next=prev;
    *head_ref=prev;
}
