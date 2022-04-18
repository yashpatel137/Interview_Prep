void StackQueue :: push(int x)
{
    s1.push(x);
}
int StackQueue :: pop()
{
    if(s1.empty())
    {
        return -1;
    }
    while(!s1.empty())
    {
        int temp=s1.top();
        s1.pop();
        s2.push(temp);
    }
    int ans = s2.top();
    s2.pop();
    while(!s2.empty())
    {
        int  temp=s2.top();
        s2.pop();
        s1.push(temp);
    }
    return ans;
}