int solve(Node *root, int k, int node, int &ans)
{
    if(!root)
    {
        return 0;
    }
    if(root->data==node)
    {
        return 1;
    }
    int ldis=solve(root->left,k,node,ans);
    int rdis=solve(root->right,k,node,ans);
    if(ldis==k || rdis==k)
    {
        ans=root->data;
        return ans;
    }
    if(ldis)
    {
        return ldis+1;
    }
    else if(rdis)
    {
        return rdis+1;
    }
    return 0;
}
int kthAncestor(Node *root, int k, int node)
{
    int ans=-1;
    solve(root,k,node,ans);
    return ans;
}
