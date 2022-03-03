class Solution
{
    public:
    void solve(Node *root, int level, vector<int> &ans)
    {
        if(root==NULL)
        {
            return;
        }
        if(level==ans.size())
        {
            ans.push_back(root->data);
        }
        solve(root->right,level+1,ans);
        solve(root->left,level+1,ans);
    }
    vector<int> rightView(Node *root)
    {
        int level=0;
        vector<int> ans;
        solve(root,level,ans);
        return ans;
    }
};