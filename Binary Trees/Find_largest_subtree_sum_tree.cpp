int solve(Node *root,int &ans)
{
    if(root==NULL)
    {
        return 0;
    }
    int tempsum=root->data+solve(root->left,ans)+solve(root->right,ans);
    ans=max(ans,tempsum);
    return tempsum;
}
int findLargestSumTree(Node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    int ans=INT_MIN;
    solve(root,ans);
    return ans;
}