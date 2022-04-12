#include<bits/stdc++.h>
using namespace std;

void insertr(stack<int> &st, int temp)
{
	if(st.size()==0 || st.top()<=temp)
	{
		st.push(temp);
		return;
	}
	int val=st.top();
	st.pop();
	insertr(st,temp);
	st.push(val);
}

void sortr(stack<int> &st)
{
	if(st.size()==1)
	{
		return;
	}
	int temp=st.top();
	st.pop();
	sortr(st);
	insertr(st,temp);
}

int main()
{
	int n;
	cin>>n;
	stack<int> st;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		st.push(x);
	}
	sortr(st);
	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}