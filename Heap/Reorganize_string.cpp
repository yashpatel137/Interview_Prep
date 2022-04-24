class Solution {
public:
    string reorganizeString(string s) 
    {
        string ans="";
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(mp[s[i]]>(n+1)/2)
            {
                return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        for(auto x:mp)
        {
            pq.push({x.second,x.first});
        }
        while(pq.size()>1)
        {
            char c1,c2;
            int t1,t2;
            c1=pq.top().second;
            t1=pq.top().first;
            ans+=c1;
            t1--;
            pq.pop();
            c2=pq.top().second;
            t2=pq.top().first;
            ans+=c2;
            t2--;
            pq.pop();
            if(t1>0)
            {
                pq.push({t1,c1});
            }
            if(t2>0)
            {
                pq.push({t2,c2});
            }
        }
        if(!pq.empty())
        {
            ans += pq.top().second;
        }
        return ans;
    }
};