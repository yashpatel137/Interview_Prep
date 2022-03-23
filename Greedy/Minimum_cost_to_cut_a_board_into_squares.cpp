#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		m--;
		n--;
		int x[m],y[n];
		for(int i=0;i<m;i++)
		{
			cin>>x[i];
		}
		for(int i=0;i<n;i++)
		{
			cin>>y[i];
		}
		sort(x,x+m,greater<int>());
		sort(y,y+n,greater<int>());
		int hc=1,vc=1;
		int ans=0,i=0,j=0;
		while(i<m && j<n)
		{
			if(x[i]>y[j])
			{
				ans+=x[i]*vc;
				hc++;
				i++;
			}
			else
			{
				ans+=y[j]*hc;
				vc++;
				j++;
			}
		}
		while(i<m)
		{
			ans+=x[i]*vc;
			i++;
		}
		while(j<n)
		{
			ans+=y[j]*hc;
			j++;
		}
		cout<<ans<<endl;
	}
	return 0;
}