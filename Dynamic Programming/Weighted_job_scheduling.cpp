class Solution 
{
    public:
    static bool cmp(Job a,Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    {
        sort(arr,arr+n,cmp);
        bool done[n]={0};
        int day=0;
        int profit=0;
        for(int i=0;i<n;i++)
        {
            for(int j=min(n,arr[i].dead-1);j>=0;j--)
            {
                if(done[j]==false)
                {
                    day+=1;
                    profit+=arr[i].profit;
                    done[j]=true;
                    break;
                }
            }
        }
        return {day,profit};
    } 
};