//Method 1
void inorder(Node *root, vector<int> &vec, unordered_set<int> &s)
{
    if(root)
    {
        inorder(root->left,vec,s);
        if(!root->left&&!root->right)
        {
            vec.push_back(root->data);
        }
        s.insert(root->data);
        inorder(root->right,vec,s);
    }
}
bool isDeadEnd(Node *root)
{
    unordered_set<int> s;
    vector<int> vec;
    inorder(root,vec,s);
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]-1<=0)
        {
            if(s.find(vec[i]+1)!=s.end())
            {
                return true;
            }
        }
        else
        {
            if(s.find(vec[i]-1)!=s.end() && s.find(vec[i]+1)!=s.end())
            {
                return true;
            }
        }
    }
    return false;
}

//Method 2
bool solve(Node *root, int min, int max)
{
    if(!root)
    {
        return false;
    }
    if(min==max)
    {
        return true;
    }
    return (solve(root->left,min,root->data-1)||solve(root->right,root->data+1,max));
}
bool isDeadEnd(Node *root)
{
    return solve(root,1,INT_MAX);
}