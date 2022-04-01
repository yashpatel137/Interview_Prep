#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    unordered_map<int,int> mp;
	    int mx=0;
	    int n=str.length();
	    for(int i=0;i<n;i++)
	    {
	        mp[str[i]]++;
	        if(mx<mp[str[i]])
	        {
	            mx=mp[str[i]];
	        }
	    }
	    if(mx<=n-mx+1)
	    {
	        cout<<1<<endl;
	    }
	    else
	    {
	        cout<<0<<endl;
	    }
	}
	return 0;
}