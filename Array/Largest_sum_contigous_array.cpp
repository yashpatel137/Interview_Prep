#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long maxSubarraySum(int arr[], int n){
        long long sum=0;
        long long max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(max<sum)
            {
                max=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return max;
    }
};
int main()
{
    int t,n;
    
    cin>>t;
    while(t--)
    {
        cin>>n; 
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}