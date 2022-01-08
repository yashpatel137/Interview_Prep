#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int> mp;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                return true;
            }
            if(mp.find(sum)!=mp.end())
            {
                return true;
            }
            mp.insert({sum,i});
        }
        return false;
    }
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}