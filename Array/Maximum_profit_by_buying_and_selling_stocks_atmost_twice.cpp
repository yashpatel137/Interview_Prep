//Method 1
int maxtwobuysell(int arr[],int size) {
    int first_buy = INT_MIN;
      int first_sell = 0;
      int second_buy = INT_MIN;
      int second_sell = 0;
      
      for(int i=0;i<size;i++) {
        
          first_buy = max(first_buy,-arr[i]);
          first_sell = max(first_sell,first_buy+arr[i]); 
          second_buy = max(second_buy,first_sell-arr[i]);
          second_sell = max(second_sell,second_buy+arr[i]);
      
    }
     return second_sell;
}

//Method 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> vec(n,0);
        int mx=prices[n-1];
        int mi=prices[0];
        for(int i=n-2;i>=0;i--)
        {
            if(mx<prices[i])
            {
                mx=prices[i];
            }
            vec[i]=max(vec[i+1],mx-prices[i]);
        }
        for(int i=1;i<n;i++)
        {
            if(mi>prices[i])
            {
                mi=prices[i];
            }
            vec[i]=max(vec[i-1],vec[i]+(prices[i]-mi));
        }
        return vec[n-1];
    }
};