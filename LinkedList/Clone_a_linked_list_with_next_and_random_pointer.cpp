class Solution
{
    public:
    Node *copyList(Node *head)
    {
        Node *iter=head,*front=head;
        while(iter!=NULL)
        {
            front=iter->next;
            Node *copy=new Node(iter->data);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        while(iter!=NULL)
        {
            if(iter->arb!=NULL)
            {
                iter->next->arb=iter->arb->next;
            }
            iter=iter->next->next;
        }
        Node *ahead=new Node(0);
        Node *copy=ahead;
        iter=head;
        while(iter!=NULL)
        {
            front =iter->next->next;
            copy->next=iter->next;
            iter->next=front;
            copy=copy->next;
            iter=iter->next;
        }
        return ahead->next;
    }

};

//Method 2
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        Node *curr=head,*temp;
        while(curr)
        {
            temp=curr->next;
            curr->next=new Node(curr->data);
            curr->next->next=temp;
            curr=temp;
        }
        curr=head;
        while(curr)
        {
            curr->next->arb=curr->arb?curr->arb->next:curr->arb;
            curr=curr->next->next;
        }
        Node *original=head,*copy=head->next;
        temp=copy;
        while(original and copy)
        {
            original->next=original->next->next;
            copy->next=copy->next?copy->next->next:copy->next;
            original=original->next;
            copy=copy->next;
        }
        return temp;
    }
};
