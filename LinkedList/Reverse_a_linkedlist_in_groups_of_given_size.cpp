class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head==NULL)
        {
            return NULL;
        }
        node *curr=head,*prev=NULL;
        int ct=0;
        while(ct<k && curr!=NULL)
        {
            node *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            ct++;
        }
        head->next=reverse(curr,k);
        return prev;
    }
};