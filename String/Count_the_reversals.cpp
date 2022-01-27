//Method 1
int countRev (string s)
{
    int n=s.length();
    if(n%2!=0)
    {
        return -1;
    }
    int count=0;
    stack<char>st;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
        {
            st.push(s[i]);
        }
        else
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push('{');
                count++;
            }
        }
    }
    count+=st.size()/2;
    return count;
}

//Method 2

int countRev (string s)
{
    int n=s.length();
    if(n%2!=0)
    {
        return -1;
    }
    int count=0,temp=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='{')
        {
            temp++;;
        }
        else
        {
            if(temp==0)
            {
                count++;
                temp++;
            }
            else
            {
                temp--;
            }
        }
    }
    count+=temp/2;
    return count;
}