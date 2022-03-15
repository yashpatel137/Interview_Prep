//Method 1
class Solution
{
    public:
    void inorder(Node *root,vector<int> &ans)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        if(!root1)
        {
            inorder(root2,ans);
            return ans;
        }
        else if(!root2)
        {
            inorder(root1,ans);
            return ans;
        }
        else
        {
            inorder(root2,ans);
            inorder(root1,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//Method 2
class Solution
{
    public:
    void helper(stack<Node*> &s,Node *root){
        while(root!=NULL){
            s.push(root);
            root=root->left;
        }
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        stack<Node*> s1,s2;
        helper(s1,root1);
        helper(s2,root2);
        while(!s1.empty() || !s2.empty()){
            int a=(s1.size())?s1.top()->data:INT_MAX;
            int b=(s2.size())?s2.top()->data:INT_MAX;
            if(a<=b){
               Node *temp=s1.top();
               s1.pop();
               ans.push_back(temp->data);
               helper(s1,temp->right);
            }
            else{
                Node *temp=s2.top();
               s2.pop();
               ans.push_back(temp->data);
               helper(s2,temp->right);
                
            }
        }
        return ans;
    }
};