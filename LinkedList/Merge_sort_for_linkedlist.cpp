class Solution{
  public:
    Node *merge(Node *left, Node *right)
    {
        Node *ans=NULL;
        if(!left)
        {
            return right;
        }
        else if(!right)
        {
            return left;
        }
        if(left->data<=right->data)
        {
            ans=left;
            ans->next=merge(left->next,right);
        }
        else
        {
            ans=right;
            ans->next=merge(left,right->next);
        }
        return ans;
    }
    void findMid(Node *curr, Node **left, Node **right)
    {
        Node *fast,*slow;
        slow=curr;
        fast=curr->next;
        while(fast!=NULL)
        {
            fast=fast->next;
            if(fast!=NULL)
            {
                slow=slow->next;
                fast=fast->next;
            }
        }
        *left=curr;
        *right=slow->next;
        slow->next=NULL;
    }
    void mergeSorting(Node **head)
    {
        Node *curr=*head;
        Node *left,*right;
        if(!curr || !curr->next)
        {
            return;
        }
        findMid(curr,&left,&right);
        mergeSorting(&left);
        mergeSorting(&right);
        *head=merge(left,right);
    }
    Node* mergeSort(Node* head) 
    {
        mergeSorting(&head);
        return head;
    }
};