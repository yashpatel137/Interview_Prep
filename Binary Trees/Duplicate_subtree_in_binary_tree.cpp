class Solution {
  public:
    unordered_map<string,int> mp;
    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }
    string solve(Node *root)
    {
        if(!root)
        {
            return "#";
        }
        string str="";
        if(isLeaf(root))
        {
            str+=to_string(root->data);
            return str;
        }
        str=str+to_string(root->data);
        str=str+solve(root->left);
        str=str+solve(root->right);
        mp[str]++;
        return str;
    }
    int dupSub(Node *root) 
    {
        solve(root);
        for(auto x:mp)
        {
            if(x.second>=2)
            {
                return 1;
            }
        }
        return 0;
    }
};