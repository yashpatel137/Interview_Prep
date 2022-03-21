class Solution
{
    public:
    static bool comp(pair<int,int> a, pair<int,int> b)
    {
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        int count=1;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int prev=0;
        for(int i=1;i<n;i++)
        {
            if(v[i].first>v[prev].second)
            {
                count++;
                prev=i;
            }
        }
        return count;
    }
};