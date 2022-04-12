#include<bits/stdc++.h>
using namespace std;
stack<char> st;
string ns;
void insert_at_bottom(char x)
{

	if(st.size() == 0)
	    st.push(x);
	else
	{			
		char a = st.top();
		st.pop();
		insert_at_bottom(x);
		st.push(a);
	}
}
void reverse()
{
	if(st.size()>0)
	{
		char x = st.top();
		st.pop();
		reverse();
		insert_at_bottom(x);
	}
}
int main()
{
	st.push('1');
	st.push('2');
	st.push('3');
	st.push('4');
	reverse();
	return 0;
}