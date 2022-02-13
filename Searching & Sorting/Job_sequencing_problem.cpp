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

//Method 2 O(NlogN)
struct Job
{
    int start, finish, profit;
};
bool myfunction(Job s1, Job s2)
{
    return (s1.finish < s2.finish);
}

int binarySearch(Job jobs[], int index)

    int lo = 0, hi = index - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
  
    return -1;
}
int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr+n, myfunction);
    int *table = new int[n];
    table[0] = arr[0].profit;
    for (int i=1; i<n; i++)
    {
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];
        table[i] = max(inclProf, table[i-1]);
    }
    int result = table[n-1];
    delete[] table;
    return result;
}