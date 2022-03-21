class NodeValue {
public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};
class Solution{
    public:
    NodeValue solve(Node* root) {
        if (!root) 
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = solve(root->left);
        auto right = solve(root->right);
        if (left.maxNode < root->data && root->data < right.minNode) 
        {
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    int largestBst(Node *root)
    {
    	return solve(root).maxSize;
    }
};