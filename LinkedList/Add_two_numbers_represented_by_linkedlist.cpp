class Solution
{
    public:
    Node *reverse(Node *head)
    {
        Node *prev=NULL,*nxt=NULL;
        Node *curr=head;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        first=reverse(first);
        second=reverse(second);
        Node *ans=new Node(0);
        Node *curr=ans;
        int sum=0;
        while(first!=NULL || second!=NULL || sum)
        {
            if(first!=NULL)
            {
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL)
            {
                sum+=second->data;
                second=second->next;
            }
            curr->next=new Node(sum%10);
            sum/=10;
            curr=curr->next;
        }
        return reverse(ans->next);
    }
};