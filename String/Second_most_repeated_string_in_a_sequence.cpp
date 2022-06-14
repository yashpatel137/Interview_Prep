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

//Method 2
unordered_map<string, int>um;
        for(int i = 0; i<n; i++)
        {
            um[arr[i]]++;
        }
        int ma = INT_MIN;
        int ma2 = INT_MIN;
        string a;
        string b;
        for(auto it: um)
        {
            if(it.second> ma)
            {
                b = a;
                a = it.first;
                ma2 = ma;
                ma = it.second;
            }
            else if(it.second>ma2)
            {
                b = it.first;
                ma2 = it.second;
            }
        }
        return b;
