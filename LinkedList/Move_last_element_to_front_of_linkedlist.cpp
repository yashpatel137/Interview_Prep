
void moveToLast(node *head)
{
    if(*head==NULL || (*head)->next==NULL)
    {
        return;
    }
    node *seclast=NULL;
    node *last=head;
    while(last->next!=NULL)
    {
        seclast=last;
        last=last->next;
    }
    seclast->next=NULL;
    last->next=head;
    head=last;
}
