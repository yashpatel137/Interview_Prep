#include<bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> s;
        int ans=0;
        for(int i=0;i<N;i++)
        {
            s.insert(arr[i]);
        }
        for(int i=0;i<N;i++)
        {
            if(s.find(arr[i]-1)==s.end())
            {
                int temp=arr[i];
                while(s.find(temp)!=s.end())
                {
                    temp++;
                }
                ans=max(ans,temp-arr[i]);
            }
        }
        return ans;
    }
};
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}