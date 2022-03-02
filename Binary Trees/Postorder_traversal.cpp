//Method recursive
void solve(Node *root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    solve(root->left,ans);
    solve(root->right,ans);
    ans.push_back(root->data);
}
vector <int> postOrder(Node* root)
{
    vector<int> ans;
    solve(root,ans);
    return ans;
}

///Method iterative
class Solution{
    public:
    vector<int> postOrder(Node* node) 
    {
        stack<Node*>st;
        vector<int> ans;
        st.push(node);
        while(!st.empty())
        {
            Node *temp=st.top();
            st.pop();
            ans.push_back(temp->data);
            if(temp->left)
            {
                st.push(temp->left);
            }
            if(temp->right)
            {
                st.push(temp->right);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};