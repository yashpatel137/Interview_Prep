class Solution {
  public:
    void mirror(Node* node) {
        if(node==NULL)
        {
            return;
        }
        queue<Node*> q;
        q.push(node);
        while(!q.empty())
        {
            Node *temp=q.front();
            q.pop();
            swap(temp->left,temp->right);
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
};