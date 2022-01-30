class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        priority_queue<pair<int,string>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        pq.pop();
        return pq.top().second;
    }
};