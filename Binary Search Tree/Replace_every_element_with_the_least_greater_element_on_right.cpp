Node* insert(Node* node, int data, Node*& succ)
{
    if (node == NULL)
        return node = newNode(data);
    if (data < node->data) {
        succ = node;
        node->left = insert(node->left, data, succ);
    }
    else if (data > node->data)
        node->right = insert(node->right, data, succ);
    return node;
}
void replace(int arr[], int n)
{
    Node* root = NULL;
    for (int i = n - 1; i >= 0; i--) {
        Node* succ = NULL;
        root = insert(root, arr[i], succ);
        if (succ)
            arr[i] = succ->data;
        else 
            arr[i] = -1;
    }
}

//Method 2
void solve(vector<int>& arr) {
    set<int> s;
    vector<int> ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--) 
    {
        s.insert(arr[i]); 
        auto it = s.upper_bound(arr[i]);
        if(it == s.end()) arr[i] = -1; 
        else arr[i] = *it; 
    }
}
