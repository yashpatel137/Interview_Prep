class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        if(n==0 || m==0)
        {
            return 0;
        }
        vector<int> vec(m+1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            stack<int> st;
            for(int j=0;j<vec.size();j++)
            {
                if(j<m)
                {
                    vec[j]=(M[i][j]==1)?vec[j]+1:0;
                }
                while(!st.empty() && vec[j]<vec[st.top()])
                {
                    int cur=st.top();
                    st.pop();
                    ans=max(ans,vec[cur]*(st.empty()?j:(j-1-st.top())));
                }
                st.push(j);
            }
        }
        return ans;
    }
};