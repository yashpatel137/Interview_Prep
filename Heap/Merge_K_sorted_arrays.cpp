class Solution
{
    public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push({arr[i][0],{i,0}});
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            auto tmp=pq.top().second;
            pq.pop();
            if(tmp.second+1<arr[tmp.first].size())
            {
                pq.push({arr[tmp.first][tmp.second+1],{tmp.first,tmp.second+1}});
            }
        }
        return ans;
    }
};