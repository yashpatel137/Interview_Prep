//Method 1
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        Node *zeroC=new Node(0);
        Node *oneC=new Node(0);
        Node *twoC=new Node(0);
        Node *zero=zeroC,*one=oneC,*two=twoC;
        Node *curr=head;
        while(curr)
        {
            if(curr->data==0)
            {
                zero->next=curr;
                zero=zero->next;
                curr=curr->next;
            }
            else if(curr->data==1)
            {
                one->next=curr;
                one=one->next;
                curr=curr->next;
            }
            else if(curr->data==2)
            {
                two->next=curr;
                two=two->next;
                curr=curr->next;
            }
        }
        zero->next=(oneC->next)?(oneC->next):(twoC->next);
        one->next=twoC->next;
        two->next=NULL;
        head=zeroC->next;
        delete oneC;
        delete twoC;
        delete zeroC;
        return head;
    }
};

//Method 2
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        Node *temp=head;
        int count[3]={0};
        while(temp!=NULL)
        {
            count[temp->data]+=1;
            temp=temp->next;
        }
        temp=head;
        int i=0;
        while(temp!=NULL)
        {
            if(count[i]==0)
            {
                i+=1;
            }
            else
            {
                temp->data=i;
                count[i]-=1;
                temp=temp->next;
            }
        }
        return head;
    }
};