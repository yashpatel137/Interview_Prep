// TLE
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>g(n);
        for(auto x:flights)
        {
            g[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push(make_tuple(0,src,0));
        while(!pq.empty())
        {
            auto [cost,u,stops]=pq.top();
            pq.pop();
            if(u==dst)
            {
                return cost;
            }
            if(stops>k)
            {
                continue;
            }
            for(auto x:g[u])
            {
                auto [v,w]=x;
                pq.push(make_tuple(cost+w,v,stops+1));
            }
        }
        return -1;
    }
};

// Method 2
class Solution {
public:
    int solve(unordered_map<int,vector<pair<int,int>>> &mp,int src, int &dst, int &n, int k, vector<vector<int>>&mem)
    {
        if(src==dst)
        {
            return 0;
        }
        if(k<0)
        {
            return -1;
        }
        if(mem[src][k]!=0)
        {
            return mem[src][k];
        }
        int ans=INT_MAX;
        for(int i=0;i<mp[src].size();i++)
        {
            int temp=solve(mp,mp[src][i].first,dst,n,k-1,mem);
            if(temp!=-1)
            {
                ans=min(ans,temp+mp[src][i].second);
            }
        }
        if(ans==INT_MAX)
        {
            ans=-1;
            mem[src][k]=-1;
            return ans;
        }
        mem[src][k]=ans;
        return ans;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i=0;i<flights.size();i++)
        {
            mp[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<vector<int>> mem(n+1,vector<int>(k+1,0));
        return solve(mp,src,dst,n,k,mem);
    }
};