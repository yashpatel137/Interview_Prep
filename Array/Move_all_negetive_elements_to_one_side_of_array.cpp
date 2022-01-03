#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        int arr1[n];
        int start=0;
        int end=n-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>=0)
            {
                arr1[start++]=arr[i];
            }
            else
            {
                arr1[end--]=arr[i];
            }
        }
        int s=0,e=n-1;
        for(int i=0;i<n;i++)
        {
            if(arr1[i]>=0)
            {
                arr[s++]=arr1[i];
            }
            else
            {
                arr[e--]=arr1[i];
            }
        }
    }
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}