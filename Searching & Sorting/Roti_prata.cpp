#include<bits/stdc++.h>
using namespace std;

int check(int *arr, int n, int p, int mid)
{
    int time=0;
    int pra=0;
    for(int i=0;i<n;i++)
    {
        time=arr[i];
        int k=2;
        while(time<=mid)
        {
            pra++;
            time+=(arr[i]*k);
            k++;
        }
    }
    if(pra>=p)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,n;
        cin>>p;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int lo=0,hi=1e8;
        int ans=0;
        while(lo<=hi)
        {
            int mid=(lo+hi)>>1;
            if(check(arr,n,p,mid))
            {
                ans=mid;
                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}