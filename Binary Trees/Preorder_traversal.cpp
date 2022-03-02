//Method recursive
void solve(Node *root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    ans.push_back(root->data);
    solve(root->left,ans);
    solve(root->right,ans);
}
vector <int> preorder(Node* root)
{
    vector<int> ans;
    solve(root,ans);
    return ans;
}

//Method iterative
vector <int> preorder(Node* root)
{
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty())
    {
        Node *temp=st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->right)
        {
            st.push(temp->right);
        }
        if(temp->left)
        {
            st.push(temp->left);
        }
    }
    return ans;
}