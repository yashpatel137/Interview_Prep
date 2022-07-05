//Using DP
class Solution{
  public:
    unordered_map<Node*,int>mp;
    int getMaxSum(Node *root) 
    {
        if(root==NULL)
        {
            return 0;

        }
        if(mp[root])
        {
            return mp[root];
        }
        int sum=root->data;
        if(root->left)
        {
            sum+=getMaxSum(root->left->left);
            sum+=getMaxSum(root->left->right);
        }
        if(root->right)
        {
            sum+=getMaxSum(root->right->left);
            sum+=getMaxSum(root->right->right);
        }
        int nonode=0;
        nonode+=getMaxSum(root->left);
        nonode+=getMaxSum(root->right);
        int ans=max(sum,nonode);
        mp[root]=ans;
        return mp[root];
    }
};

//Using pair
pair<int, int> maxSumHelper(Node *root)
{
    if (root==NULL)
    {
        pair<int, int> sum(0, 0);
        return sum;
    }
    pair<int, int> sum1 = maxSumHelper(root->left);
    pair<int, int> sum2 = maxSumHelper(root->right);
    pair<int, int> sum;
 
    sum.first = sum1.second + sum2.second + root->data;

    sum.second = max(sum1.first, sum1.second) + max(sum2.first, sum2.second);
 
    return sum;
}
 
int maxSum(Node *root)
{
    pair<int, int> res = maxSumHelper(root);
    return max(res.first, res.second);
}

//Using Memoization
vector<vector<int>> dp;
int cnt = 0;
Node *temp;
Node *giveIndex(Node *root)
{
    if (root == NULL)
        return NULL;
    Node *newNode1 = newNode(cnt++);
    newNode1->left = giveIndex(root->left);
    newNode1->right = giveIndex(root->right);
    return newNode1;
}
int solve(Node *root, int b, Node *temp)
{
    if (root == NULL)
        return 0;
    if (dp[temp->data][b] != -1)
        return dp[temp->data][b];
    int res;
    if (b == 0)
        res = max(root->data + solve(root->right, 1, temp->right) + solve(root->left, 1, temp->left), solve(root->right, 0, temp->right) + solve(root->left, 0, temp->left));
 
    else
        res = solve(root->right, 0, temp->right) + solve(root->left, 0, temp->left);

    return dp[temp->data][b] = res;
}
int getMaxSum(Node *root)
{
    dp = vector<vector<int>>(100, vector<int>(2, -1));
    temp = giveIndex(root);
    int res = solve(root, 0, temp);
 
    return res;
}
