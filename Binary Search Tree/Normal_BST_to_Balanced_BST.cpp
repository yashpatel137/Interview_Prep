void inorder(Node *root, vector<Node*> &in)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,in);
    in.push_back(root);
    inorder(root->right,in);
}
Node *solve(Node *root,vector<Node*> in,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=start+(end-start)/2;
    root=in[mid];
    root->left=solve(root,in,start,mid-1);
    root->right=solve(root,in,mid+1,end);
    return root;
}
Node* buildBalancedTree(Node* root)
{
    if(!root)
    {
        return root;
    }
	vector<Node*> in;
	inorder(root,in);
	return solve(root,in,0,in.size()-1);
}