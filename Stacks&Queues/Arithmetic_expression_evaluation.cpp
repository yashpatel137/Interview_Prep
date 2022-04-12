class Solution
{
    public:
    int evaluatePostfix(string S)
    {
        stack<int>st;
        for(auto x:S)
        {
            if(x>='0' && x<='9')
            {
                st.push(x-'0');
            }
            else
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                if(x=='*')
                {
                    st.push(b*a);
                }
                else if(x=='/')
                {
                    st.push((b/a));
                }
                else if(x=='+')
                {
                    st.push((b+a));
                }
                else
                {
                    st.push((b-a));
                }
            }
        }
        return st.top();
    }
};