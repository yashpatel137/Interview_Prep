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

//Method 3
int findposition(int in[],int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        return -1;
    }
    Node*solve(int in[],int pre[],int &index,int start,int end,int n){
      
        if(index>=n||start>end){
            return NULL;
        }
        int element=pre[index++];
        Node*root=new Node(element);
        int position=findposition(in,element,n);
        root->left=solve(in,pre,index,start,position-1,n);
        root->right=solve(in,pre,index,position+1,end,n);
        return root;
        
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        Node*ans=solve(in,pre,preorderindex,0,n-1,n);
        return ans;
        
    }
