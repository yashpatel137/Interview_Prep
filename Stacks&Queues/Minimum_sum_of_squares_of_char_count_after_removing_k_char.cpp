class Solution{
public:
    int minValue(string s, int k)
    {
        int ans=0;
        int l=s.length();
        vector<int>cnt(26,0);
        if(k>=l)
        {
            return 0;
        }
        for(int i=0;i<l;i++)
        {
            cnt[s[i]-'a']++;
        }
        priority_queue<int>q;
        for(int i=0;i<cnt.size();i++)
        {
            q.push(cnt[i]);
        }
        while(k--)
        {
            int temp=q.top();
            q.pop();
            temp-=1;
            q.push(temp);
        }
        while(!q.empty())
        {
            int temp=q.top();
            q.pop();
            ans+=temp*temp;
        }
        return ans;
    }
};