#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,q;
        cin>>n;
        cin>>q;
        vector<pair<long long int,long long int>> vec;
        for(long long int i=0;i<n;i++)
        {
            long long int x,y;
            cin>>x>>y;
            vec.push_back({x,y});
        }
        //Sorting
        sort(vec.begin(),vec.end());
        long long int id=0;
        //Merge intervals
        for(long long int i=1;i<vec.size();i++)
        {
            if(vec[id].second >= vec[i].first)
            {
                vec[id].second = max(vec[id].second,vec[i].second);
            }
            else
            {
                id++;
                vec[id]=vec[i];
            }
        }
        //Searching
        while(q--)
        {
            long long int k;
            cin>>k;
            long long int ans=-1;
            for(long long int i=0;i<=id;i++)
            {
                if((vec[i].second - vec[i].first + 1)>=k)
                {
                    ans=vec[i].first+k-1;
                    break;
                }
                else
                {
                    k=k-(vec[i].second - vec[i].first + 1);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}