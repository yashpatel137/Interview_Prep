class Solution
{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(),a.end());
        long long i=0,j=m-1,ans=INT_MAX;
        while(j<n)
        {
            ans=min(a[j++]-a[i++],ans);
        }
        return ans;
    }   
};