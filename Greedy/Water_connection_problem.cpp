class Solution
{
    public:
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<int>> ans;
        vector<int> start;
        map<int,int> x;
        map<int,int> y;
        for(int i=0;i<p;i++)
        {
            x.insert({a[i],i});
            y.insert({b[i],i});
        }
        for(int i=0;i<p;i++)
        {
            if(y.find(a[i])==y.end())
            {
                start.push_back(a[i]);
            }
        }
        sort(start.begin(),start.end());
        for(int i=0;i<start.size();i++)
        {
            int source=start[i];
            int mn=INT_MAX;
            int dest=-1;
            int temp=source;
            while(x.find(temp)!=x.end())
            {
                mn=min(mn,d[x[temp]]);
                temp=b[x[temp]];
                dest=temp;
            }
            ans.push_back({source,dest,mn});
        }
        return ans;
    }
};