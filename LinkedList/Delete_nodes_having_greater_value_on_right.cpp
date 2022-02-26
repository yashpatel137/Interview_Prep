//Method 1
class Solution
{
    
    Node *reverse(Node *head)
    {
        Node *prev=NULL,*curr=head,*nex;
        while(curr!=NULL)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    public:
    Node *compute(Node *head)
    {
        Node *temp=reverse(head);
        Node *rev=temp;
        while(rev->next!=NULL)
        {
            if(rev->data>rev->next->data)
            {
                rev->next=rev->next->next;
            }
            else
            {
                rev=rev->next;
            }
        }
        head=reverse(temp);
        return head;
    }
    
};

//Method 2

class Solution
{
   public:
   Node *compute(Node *head)
   {
       if(head->next==NULL)
       {
           return head;
       }
       else 
       {
           head->next=compute(head->next);
       }
       if(head->data<head->next->data)
       {
           Node *temp=head;
           head=head->next;
           free (temp);
       }
       return head;
   }
};