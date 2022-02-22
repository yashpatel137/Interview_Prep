Node* reverseDLL(Node * head)
{
    Node *nex=NULL,*curr=head;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    while(curr)
    {
        nex=curr->prev;
        curr->prev=curr->next;
        curr->next=nex;
        curr=curr->prev;
    }
    /*if(nex!=NULL)
    {
        head=nex->prev;
    }*/
    return nex->prev;
}