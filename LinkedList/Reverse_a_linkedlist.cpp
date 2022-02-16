//Recursion

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node *temp=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    
};

//Iterative

class Solution
{
    public:
    struct Node* reverseList(struct Node *head)
    {
        Node *curr=head,*prev=NULL,*next=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
        return head;
    }
    
};