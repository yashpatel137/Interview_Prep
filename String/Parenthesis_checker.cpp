class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> st;
        bool ans=true;
        if(x.size()==1)
        {
            return 0;
        }
        if(x[0]==']' || x[0]==')' || x[0]=='}')
        {
            return 0;
        }
        for(auto ch:x)
        {
            if(ch=='{' || ch=='[' || ch=='(')
            {
                st.push(ch);
            }
            else if(!st.empty() && ch=='}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if(!st.empty() && ch==']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
            else if(!st.empty() && ch==')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                }
                else
                {
                    ans=false;
                    break;
                }
            }
        }
        if(!st.empty())
        {
            return 0;
        }
        else
        {
            return ans;
        }
    }

};