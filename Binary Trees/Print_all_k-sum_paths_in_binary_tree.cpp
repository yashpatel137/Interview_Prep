void solve(Node *root, vector<int> &path, int k)
{
    if(root==NULL)
    {
        return;
    }
    path.push_back(root->data);
    solve(root->left,path,k);
    solve(root->right,path,k);
    int sum=0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum+=path[i];
        if(sum==k)
        {
            for(int j=i;j<path.size();j++)
            {
                cout<<path[j]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
}
void paths(Node *root,int k)
{
    vector<int> path;
    solve(root,path,k);
}