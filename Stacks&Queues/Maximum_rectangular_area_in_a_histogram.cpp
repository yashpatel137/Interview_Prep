class Solution
{
    public:
    long long getMaxArea(long long arr[], int n)
    {
        long long i=0;
        long long mx=0;
        stack<long long> st;
        while(i<n)
        {
            if(st.empty() || arr[st.top()]<=arr[i])
            {
                st.push(i++);
            }
            else
            {
                long long temp=st.top();
                st.pop();
                long long ans=arr[temp]*(st.empty()?i:(i-st.top()-1));
                mx=max(mx,ans);
            }
        }
        while(!st.empty())
        {
            long long temp=st.top();
            st.pop();
            long long ans=arr[temp]*(st.empty()?i:(i-st.top()-1));
            mx=max(mx,ans);
        }
        return mx;
    }
};