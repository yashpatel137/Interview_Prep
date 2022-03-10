class Solution{
    public:
    Node *lca(Node *root,int a,int b)
    {
        if(root==NULL)
        {
            return root;
        }
        if(root->data==a || root->data==b)
        {
            return root;
        }
        Node *leftd=lca(root->left,a,b);
        Node *rightd=lca(root->right,a,b);
        if(leftd && rightd)
        {
            return root;
        }
        else if(leftd)
        {
            return leftd;
        }
        else
        {
            return rightd;
        }
    }
    int dist(Node *common,int x,int len)
    {
        if(common==NULL)
        {
            return -1;
        }
        if(common->data==x)
        {
            return len;
        }
        int left=dist(common->left,x,len+1);
        if(left!=-1)
        {
            return left;
        }
        return dist(common->right,x,len+1);
    }
    int findDist(Node* root, int a, int b) 
    {
        Node *common=lca(root,a,b);
        int ldist=dist(common,a,0);
        int rdist=dist(common,b,0);
        return ldist+rdist;
    }
};