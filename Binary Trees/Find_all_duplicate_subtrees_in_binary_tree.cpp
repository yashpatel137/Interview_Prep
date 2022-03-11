string solve(Node *root,unordered_map<string,int> &mp, vector<Node*> &ans)
{
    if(!root)
    {
        return "";
    }
    string temp="(";
    temp+=solve(root->left,mp,ans);
    temp+=to_string(root->data);
    temp+=solve(root->right,mp,ans);
    temp+=")";
    if(mp[temp]==1)
    {
        ans.push_back(root);
    }
    mp[temp]++;
    return temp;
}
vector<Node*> printAllDups(Node* root)
{
    vector<Node*> ans;
    unordered_map<string,int> mp;
    solve(root,mp,ans);
    return ans;
}