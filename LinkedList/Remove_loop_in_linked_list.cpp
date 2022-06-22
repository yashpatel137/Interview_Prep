class Solution
{
    public:
    void removeLoop(Node* head)
    {
        Node *slow=head,*fast=head;
        bool flag=false;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                flag=true;
                break;
            }
        }
        slow=head;
        if(flag==false)
        {
            return;
        }
        else
        {
            while(slow!=fast)
            {
                slow=slow->next;
                fast=fast->next;
            }
            while(fast->next!=slow)
            {
                fast=fast->next;
            }
            fast->next=NULL;
        }
    }
};
