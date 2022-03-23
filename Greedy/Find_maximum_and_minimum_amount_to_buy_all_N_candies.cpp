class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        sort(candies,candies+n);
        int i=0,j=n-1;
        vector<int>ans;
        int ans1=0,ans2=0;
        while(i<=j)
        {
            ans1+=candies[i];
            j-=k;
            i++;
        }
        i=0;
        j=n-1;
        while(i<=j)
        {
            ans2+=candies[j];
            i+=k;
            j--;
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};