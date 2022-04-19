vector<long long> printFirstNegativeInteger(long long int arr[],long long int n, long long int k) 
{
    vector<long long> ans;
    queue<long long> q;
    for(int i=0;i<k-1;i++)
    {
        if(arr[i]<0)
        {
            q.push(arr[i]);
        }
    }
    for(int i=k-1;i<n;i++)
    {
        if(arr[i]<0)
        {
            q.push(arr[i]);
        }
        if(!q.empty())
        {
            ans.push_back(q.front());
            if(q.front()==arr[i-k+1])
            {
                q.pop();
            }
        }
        else
        {
            ans.push_back(0);
        }
    }
    return ans;
}