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
    Node* addOne(Node *head) 
    {
        head=reverse(head);
        Node *curr=head;
        while(curr!=NULL)
        {
            if(curr->next==NULL && curr->data==9)
            {
                curr->data=1;
                Node *temp=new Node(0);
                temp->next=head;
                head=temp;
            }
            else if(curr->data==9)
            {
                curr->data=0;
            }
            else
            {
                curr->data=curr->data+1;
                break;
            }
            curr=curr->next;
        }
        head=reverse(head);
        return head;
    }
};