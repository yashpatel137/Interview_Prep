class Solution 
{
    public:
        int solve(vector<vector<int>>&cost, int i, int depth, vector<bool>& visited)
        {
            const int n = cost.size();
            if(depth==n)
            {
                return cost[i][0];
            }
            int ans=INT_MAX;
            visited[i] = true;
            for(int j=0;j<n;j++)
            {
                if(!visited[j])
                {
                    visited[j] = true;
                    ans = min(ans, cost[i][j] + solve(cost, j, depth+1, visited));
                    visited[j] = false;
                }
            }
            visited[i] = false;
            return ans;
        }
        int total_cost(vector<vector<int>>cost)
        {
            vector<bool> visited(cost.size(), false);
            return solve(cost, 0, 1, visited);
        }
};