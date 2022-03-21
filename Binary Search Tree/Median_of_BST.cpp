//Method 1
void inorder(Node *root, vector<int> &vec)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}
float findMedian(struct Node *root)
{
    vector<int> ans;
    inorder(root,ans);
    int n=ans.size();
    if(n%2==0)
    {
        return (((float)(ans[n/2])+(float)ans[(n/2)-1])/2);
    }
    else
    {
        return float(ans[n/2]);
    }
}

//Method 2
int countNode(Node *root)
{
    if(!root)
    {
        return 0;
    }
    int l=countNode(root->left);
    int r=countNode(root->right);
    return l+r+1;
}
void solve(Node *root, int k, bool even, float &ans, int &curr, Node *&prev)
{
    if(!root)
    {
        return;
    }
    solve(root->left,k,even,ans,curr,prev);
    if(curr==k)
    {
        if(even)
        {
            ans=((float)prev->data+(float)root->data)/2;
        }
        else
        {
            ans=root->data;
        }
    }
    prev=root;
    curr++;
    solve(root->right,k,even,ans,curr,prev);
}
float findMedian(struct Node *root)
{
    int countnode=countNode(root);
    int currNode=1;
    bool even=true;
    int k=0;
    if(countnode%2==0)
    {
        even=true;
    }
    else
    {
        even=false;
    }
    k=countnode/2+1;
    float ans=0;
    Node *prev=NULL;
    solve(root,k,even,ans,currNode,prev);
    return ans;
}