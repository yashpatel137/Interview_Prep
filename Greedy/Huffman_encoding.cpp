class Solution
{
	public:
	    struct Node
	    {
	        int data;
	        Node *left,*right;
	        Node(int x)
	        {
	            data=x;
	            left=right=NULL;
	        }
	    };
	    struct comp
	    {
	        bool operator()(Node *a, Node *b)
	        {
	            return a->data>b->data;
	        }
	    };
	    void preorder(Node *root, vector<string> &ans, string x)
	    {
	        if(!root)
	        {
	            return;
	        }
	        if(root->left==NULL && root->right==NULL)
	        {
	            ans.push_back(x);
	            return;
	        }
	        preorder(root->left,ans,x+"0");
	        preorder(root->right,ans,x+"1");
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector<string> ans;
		    priority_queue<Node*,vector<Node*>,comp>pq;
		    for(int i=0;i<f.size();i++)
		    {
		        Node *temp=new Node(f[i]);
		        pq.push(temp);
		    }
		    while(pq.size()>1)
		    {
		        Node *temp1=pq.top();
		        pq.pop();
		        Node *temp2=pq.top();
		        pq.pop();
		        Node *temp=new Node(temp1->data+temp2->data);
		        temp->left=temp1;
		        temp->right=temp2;
		        pq.push(temp);
		    }
		    preorder(pq.top(),ans,"");
		    return ans;
		}
};