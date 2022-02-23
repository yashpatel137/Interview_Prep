struct compare{
    bool compare(struct Node *first, struct Node *second)
    {
        return first->data > second->data;
    }
};

struct Node *sort(Node *head, int k)
{
    if(head==NULL)
    {
        return head;
    }
    priority_queue<Node*,vector<Node*>,compare> pq;
    Node *newhead=NULL,*curr;
    for(int i=0;head!=NULL && i<=k;i++)
    {
        pq.push(head);
        head=head->next;
    }
    while(!pq.empty())
    {
        if(newhead==NULL)
        {
            newhead=pq.top();
            newhead->prev=NULL;
            curr=newhead;
        }
        else
        {
            curr->next=pq.top();
            pq.top()->prev=curr;
            curr=pq.top();
        }
        pq.pop();
        if(head!=NULL)
        {
            pq.push(head);
            head=head->next;
        }
    }
    curr->next=NULL;
    return newhead;
}