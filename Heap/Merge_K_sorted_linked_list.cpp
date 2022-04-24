class Solution{
  public:
    struct compare
    {
        bool operator()(Node *a, Node *b)
        {
            return a->data > b->data;
        }
    };
    Node * mergeKLists(Node *arr[], int K)
    {
        Node *head=NULL,*prev;
        priority_queue<Node*,vector<Node*>,compare> pq;
        for(int i=0;i<K;i++)
        {
            if(arr[i]!=NULL)
            {
                pq.push(arr[i]);
            }
        }
        while(!pq.empty())
        {
            Node *temp=pq.top();
            pq.pop();
            if(temp->next!=NULL)
            {
                pq.push(temp->next);
            }
            if(head==NULL)
            {
                head=temp;
                prev=temp;
            }
            else
            {
                prev->next=temp;
                prev=temp;
            }
        }
        return head;
    }
};