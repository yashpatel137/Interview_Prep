#include<bits/stdc++.h>
using namespace std;

int main()
{
	while(true)
	{
		int n;
		cin>>n;
		if(n==0)
		{
			break;
		}
		else
		{
			int arr1[n];
			for(int i=0;i<n;i++)
			{
				cin>>arr1[i];
			}
			int m;
			cin>>m;
			int arr2[m];
			for(int i=0;i<m;i++)
			{
				cin>>arr2[i];
			}
			int sa1=0,sa2=0;
			int i=0,j=0;
			int ans=0;
			while(i<n && j<m)
			{
				if(arr1[i]<arr2[j])
				{
					sa1+=arr1[i];
					i++;
				}
				else if(arr1[i]>arr2[j])
				{
					sa2+=arr2[j];
					j++;
				}
				else
				{
					ans+=max(sa1,sa2)+arr1[i];
					sa1=sa2=0;
					i++;
					j++;
				}
			}
			while(i<n)
			{
				sa1+=arr1[i];
				i++;
			}
			while(j<m)
			{
				sa2+=arr2[j];
				j++;
			}
			ans+=max(sa1,sa2);
			cout<<ans<<endl;
		}
	}
	return 0;
}