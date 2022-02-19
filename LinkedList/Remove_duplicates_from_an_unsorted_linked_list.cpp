class Solution
{
    public:
    Node * removeDuplicates( Node *head) 
    {
        unordered_map<int,int>mp;
        Node *curr=head,*prev=NULL;
        while(curr)
        {
            mp[curr->data]++;
            if(mp[curr->data]>=2)
            {
                mp[curr->data]--;
                Node *temp=curr;
                prev->next=curr->next;
                curr=curr->next;
                delete(temp);
            }
            else
            {
                prev=curr;
                curr=curr->next;
            }
        }
        return head;
    }
};