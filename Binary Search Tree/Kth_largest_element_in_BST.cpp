//Method 1
class Solution
{
    public:
    void inorder(Node *root, vector<int>&ans)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    int kthLargest(Node *root, int K)
    {
        vector<int> ans;
        inorder(root,ans);
        reverse(ans.begin(),ans.end());
        return ans[K-1];
    }
};

//Method 2
class Solution
{
    public:
    void solve(Node *root, int K, int &count,int &ans)
    {
        if(!root)
        {
            return;
        }
        solve(root->right,K,count,ans);
        count++;
        if(count==K)
        {
            ans=root->data;
            return;
        }
        solve(root->left,K,count,ans);
    }
    int kthLargest(Node *root, int K)
    {
        int count=0,ans;
        solve(root,K,count,ans);
        return ans;
    }
};