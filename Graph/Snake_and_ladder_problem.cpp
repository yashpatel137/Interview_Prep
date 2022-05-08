class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board)
    {
        int n=board.size();
        int steps=0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<int>q;
        q.push(1);
        vis[n-1][0]=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int p=q.front();
                q.pop();
                if(p==n*n)
                {
                    return steps;
                }
                for(int k=1;k<=6;k++)
                {
                    int curr=p+k;
                    int r=n-(curr-1)/n -1;
                    int c=(curr-1)%n;
                    if(curr>n*n)
                    {
                        break;
                    }
                    if(r%2==n%2)
                    {
                        c=n-1-(curr-1)%n;
                    }
                    if(vis[r][c]==1)
                    {
                        continue;
                    }
                    vis[r][c]=1;
                    if(board[r][c]==-1)
                    {
                        q.push(p+k);
                    }
                    else
                    {
                        q.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};