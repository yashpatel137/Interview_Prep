class Solution {
  public:
    vector <int> bottomView(Node *root) {
        vector<int> vec;
        if(root==NULL)
        {
            return vec;
        }
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        q.push({root,0});
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int line=it.second;
            Node *temp=it.first;
            mp[line]=temp->data;
            if(temp->left!=NULL)
            {
                q.push({temp->left,line-1});
            }
            if(temp->right!=NULL)
            {
                q.push({temp->right,line+1});
            }
        }
        for(auto it:mp)
        {
            vec.push_back(it.second);
        }
        return vec;
    }
};