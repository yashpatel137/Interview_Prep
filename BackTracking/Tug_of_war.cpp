#include<bits/stdc++.h>
using namespace std;
int mindiff=INT_MAX;
vector<vector<int>> ans;
void solve(int arr[], int idx, vector<int> set1, vector<int> set2, int soset1, int soset2,int n)
{
    if(idx==n)
    {
        int temp=abs(soset1-soset2);
        if(temp<mindiff)
        {
            ans.clear();
            mindiff=temp;
            ans.push_back(set1);
            ans.push_back(set2);
        }
    }
    if(set1.size()<(n+1)/2)
    {
        set1.push_back(arr[idx]);
        solve(arr,idx+1,set1,set2,soset1+arr[idx],soset2,n);
        set1.pop_back();
    }
    if(set2.size()<(n+1)/2)
    {
        set2.push_back(arr[idx]);
        solve(arr,idx+1,set1,set2,soset1,soset2+arr[idx],n);
        set2.pop_back();
    }
}

int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> set1,set2;
    int soset1=0,soset2=0;
    int idx=0;
    solve(arr, idx, set1, set2, soset1, soset2,n);
    return 0;
}