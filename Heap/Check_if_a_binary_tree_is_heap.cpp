class Solution {
  public:
    bool isHeap(struct Node* tree) 
    {
        queue<Node*> q;
        q.push(tree);
        while(!q.empty())
        {
            Node *temp =q.front();
            if(temp==NULL)
            {
                break;
            }
            q.pop();
            if(temp->left)
            {
                if(temp->left->data>temp->data)
                {
                    return false;
                }
                else
                {
                   q.push(temp->left); 
                }
            }
            if(temp->right)
            {
                if(temp->right->data>temp->data)
                {
                    return false;
                }
                else
                {
                    q.push(temp->right);
                }
            }
            else
            {
                q.push(NULL);
            }
        }
        while(!q.empty())
        {
            if(q.front()!=NULL)
            {
                return false;
            }
            q.pop();
        }
        return true;
    }
};