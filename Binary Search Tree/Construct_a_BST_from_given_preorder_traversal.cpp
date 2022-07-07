//Method 1 O(n)

node* constructTreeUtil(int pre[], int* preIndex, int key,int min, int max, int size)
{
    if (*preIndex >= size)
        return NULL;
    node* root = NULL;
    if (key > min && key < max) 
    {
        root = newNode(key);
        *preIndex = *preIndex + 1;
        if (*preIndex < size) 
        {
            root->left = constructTreeUtil(pre, preIndex, pre[*preIndex],min, key, size);
        }
        if (*preIndex < size) 
        {
            root->right = constructTreeUtil(pre, preIndex,pre[*preIndex],key, max, size);
        }
    }
    return root;
}
node* constructTree(int pre[], int size)
{
    int preIndex = 0;
    return constructTreeUtil(pre, &preIndex, pre[0],INT_MIN, INT_MAX, size);
}

//Method 2 O(n^2)

class Node {
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data)
  {
    this->data = data;
    this->left = this->right = NULL;
  }
};
static Node* node;
Node* createNode(Node* node, int data)
{
  if (node == NULL)
    node = new Node(data);
 
  if (node->data > data)
    node->left = createNode(node->left, data);
  if (node->data < data)
    node->right = createNode(node->right, data);
 
  return node;
}
void create(int data)
{
  node = createNode(node, data);
}
void inorderRec(Node* root)
{
  if (root != NULL) {
    inorderRec(root->left);
    cout<<root->data<<endl;
    inorderRec(root->right);
  }
}
int main()
{
  vector<int> nodeData = { 10, 5, 1, 7, 40, 50 };
 
  for (int i = 0; i < nodeData.size(); i++) {
    create(nodeData[i]);
  }
  inorderRec(node);
}
