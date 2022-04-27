class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>>pq(arr,arr+n);
        if(n<=1)
        {
            return 0;
        }
        long long ans=0;
        while(pq.size()>=2)
        {
            long long x=pq.top();
            pq.pop();
            long long y=pq.top();
            pq.pop();
            ans+=x+y;
            pq.push(x+y);
        }
        return ans;
    }
};