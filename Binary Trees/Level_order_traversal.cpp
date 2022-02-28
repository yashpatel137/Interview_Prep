class Solution
{
    public:
    vector<int> levelOrder(Node* node)
    {
        vector<int> ans;
        if(!node)
        {
            return ans;
        }
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node *temp=q.front();
            ans.push_back(temp->data);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            q.pop();
        }
        return ans;
    }
};