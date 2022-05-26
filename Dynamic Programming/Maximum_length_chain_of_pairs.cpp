//Method 1 dp memoization
int dp[107][107];
int solve(int i,int j,struct val p[],int n)
{
    int take=0,nottake=0;
    if(j<0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    if(i==n||(p[i].first>p[j].second))
    {
        take=1+solve(j,j-1,p,n);
    }
    nottake=solve(i,j-1,p,n);
    return dp[i][j]=max(take,nottake);
}
bool comp(struct val a,struct val b)
{
    return a.second<b.second;
}
int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,comp);
    memset(dp,-1,sizeof(dp));
    return solve(n,n-1,p,n);
}

//Method 2
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.second==b.second) return a.first<b.first;
    return a.second<b.second;
}

int maxChainLen(struct val p[],int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++){
        v.push_back({p[i].first,p[i].second});
    }
    
    sort(v.begin(),v.end(),cmp);
   
    int i=0,j=1,count=1;
    while(j<n){
        if(v[i].second < v[j].first){
            count++;
            i=j;
        }
        j++;
    }
    
    return count;
}