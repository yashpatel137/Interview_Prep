class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int min=prices[0];
        for(int i=1;i<n;i++)
        {
            if(prices[i]<min)
            {
                min=prices[i];
            }
            if(ans<(prices[i]-min))
            {
                ans=prices[i]-min;
            }
        }
        return ans;
    }
};