//TLE error in some ide
class Solution{
    public:
    Node *buildnode(int* in,int instart,int inend,int* pre,int prestart,int preend,map<int,int> inmap)
    {
        if(prestart>preend || instart>inend)
        {
            return NULL;
        }
        Node *root=new Node(pre[prestart]);
        int inroot=inmap[root->data];
        int numleft=inroot-instart;
        root->left=buildnode(in,instart,inroot-1,pre,prestart+1,prestart+numleft,inmap);
        root->right=buildnode(in,inroot+1,inend,pre,prestart+numleft+1,preend,inmap);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,int> inmap;
        for(int i=0;i<n;i++)
        {
            inmap[in[i]]=i;
        }
        Node *root=buildnode(in,0,n-1,pre,0,n-1,inmap);
        return root;
    }
};

//Method 2
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        if(n==0)
        {
            return NULL;
        }
        int i=0;
        Node *root=new Node(pre[0]);
        for(i=0;i<n;i++)
        {
            if(in[i]==pre[0])
            {
                break;
            }
        }
        root->left=buildTree(in,pre+1,i);
        root->right=buildTree(in+i+1,pre+i+1,n-i-1);
        return root;
    }
};