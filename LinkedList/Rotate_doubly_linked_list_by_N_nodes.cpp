class Solution {
public:
    Node *update(Node *start,int p)
    {
        if(p==0)
        {
            return start;
        }
        Node *temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=start;
        start->prev=temp;
        temp=start;
        int cnt=0;
        while(cnt<p)
        {
            temp=temp->next;
            cnt++;
        }
        temp->prev->next=NULL;
        temp->prev=NULL;
        return temp;
    }
};