class Solution{
  public:
    Node *solve(vector<int> in,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid=(start+end)/2;
        Node *root=new Node(in[mid]);
        root->left=solve(in,start,mid-1);
        root->right=solve(in,mid+1,end);
        return root;
    }
    void inorder(Node *root, vector<int> &in)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,in);
        in.push_back(root->data);
        inorder(root->right,in);
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> in;
        inorder(root,in);
        sort(in.begin(),in.end());
        int size=in.size();
        Node *ans=solve(in,0,size-1);
        return ans;
    }
};