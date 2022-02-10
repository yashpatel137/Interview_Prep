#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin>>size;
    int arr[size];
    vector<pair<int,int>> ans;
    for(int i=0;i<size;i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
    }
    int rnd;
    cin>>rnd;
    for(int i=0;i<rnd;i++)
    {
        int pwr;
        cin>>pwr;
        int totalpwr=0;
        int cnt=0;
        for(int j=0;j<size;j++)
        {
            if(arr[j]<=pwr)
            {
                cnt++;
                totalpwr+=arr[j];
            }
        }
        ans.push_back({cnt,totalpwr});
    }
    for(auto it:ans)
    {
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}