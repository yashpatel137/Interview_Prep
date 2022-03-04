class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> ans;
    	if(root==NULL)
    	{
    	    return ans;
    	}
    	queue<Node*>q;
    	q.push(root);
    	int level=0;
    	while(!q.empty())
    	{
    	    int size=q.size();
    	    int vs=ans.size();
    	        for(int i=0;i<size;i++)
    	        {
    	            Node *temp=q.front();
    	            q.pop();
    	            ans.push_back(temp->data);
    	            if(temp->left)
    	            {
    	                q.push(temp->left);
    	            }
    	            if(temp->right)
    	            {
    	                q.push(temp->right);
    	            }
    	        }
    	  
    	    if(level%2==1)
    	    {
    	        reverse(ans.begin()+vs,ans.end());
    	    }
    	    level++;
    	}
    	return ans;
    }
};