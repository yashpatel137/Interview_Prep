//Method 1
class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll,ll> mp;
        ll sum=0;
        ll ans=0;
        mp[0]=1;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(mp.find(sum)!=mp.end())
            {
                ans+=mp[sum];
            }
            mp[sum]+=1;
        }
        return ans;
    }
};

//Method 2
vector< pair<int, int> > findSubArrays(int arr[], int n)
{
    unordered_map<int, vector<int> > map;
    vector <pair<int, int>> out;

    int sum = 0;
 
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
 
        if (sum == 0)
            out.push_back(make_pair(0, i));
 
        if (map.find(sum) != map.end())
        {
            vector<int> vc = map[sum];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }
        map[sum].push_back(i);
    }
    return out;
}