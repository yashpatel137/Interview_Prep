class Solution
{
    public:
    void solve(stack<int>&s,int size,int curr)
    {
        if(curr==size/2)
        {
            s.pop();
            return;
        }
        int temp=s.top();
        s.pop();
        curr+=1;
        solve(s,size,curr);
        s.push(temp);
    }
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        solve(s,sizeOfStack,0);
    }
};