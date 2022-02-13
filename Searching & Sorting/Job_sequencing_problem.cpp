/*struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp(Job a, Job b)
    {
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        vector<bool> vis(n,false);
        int maxp=0,jobc=0;
        vector<int> ans(2,0);
        for(int i=0;i<n;i++)
        {
            for(int j=arr[i].dead-1;j>=0;j--)
            {
                if(vis[j])
                {
                    continue;
                }
                else
                {
                    vis[j]=true;
                    maxp+=arr[i].profit;
                    jobc++;
                    break;
                }
            }
        }
        ans[0]=jobc;
        ans[1]=maxp;
        return ans;
    } 
};