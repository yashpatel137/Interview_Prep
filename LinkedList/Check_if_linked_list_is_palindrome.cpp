class Solution{
  public:
    Node *reverse(Node *head_ref)
    {
        Node *prev=NULL,*nxt=NULL,*curr=head_ref;
        while(curr!=NULL)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    bool isPalindrome(Node *head)
    {
        Node *slow=head,*fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *head2=slow->next;
        slow->next=NULL;
        head2=reverse(head2);
        while(head!=NULL && head2!=NULL)
        {
            if((head->data)!=(head2->data))
            {
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};