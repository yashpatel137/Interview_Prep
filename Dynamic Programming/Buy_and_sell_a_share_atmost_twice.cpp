//Method 1 TC=O(n) SC=O(1)
int maxProfit(vector<int>&price)
{
    int fb=INT_MIN,fs=0,sb=INT_MIN,ss=0;
    for(int i=0;i<price.size();i++)
    {
        fb=max(fb,-price[i]);
        fs=max(fs,fb+price[i]);
        sb=max(sb,fs-price[i]);
        ss=max(ss,sb+price[i]);
    }
    return ss;
}

//Method 2 TC=O(n) SC=O(n)
int maxProfit(vector<int>&price)
{
   int n = price.size();
   int sell[n];
   sell[0] = 0;
   int minPrice = price[0], maxProfit = 0;
   for(int i = 0; i < n; i++){
       if(price[i] - minPrice > maxProfit){
           sell[i] = maxProfit = price[i] - minPrice;
       }
       else sell[i] = maxProfit;
       minPrice = min(minPrice,price[i]);
   }
   
   int buy[n];
   buy[n-1] = 0;
   int maxPrice = price[n-1];
   maxProfit = 0;
   for(int i = n-2; i >= 0; i--){
       if(maxPrice - price[i] > maxProfit){
           buy[i] = maxProfit = maxPrice - price[i];
       }
       else buy[i] = maxProfit;
       maxPrice = max(maxPrice,price[i]);
   }
   
   maxProfit = 0;
   for(int i = 0; i < n; i++){
       maxProfit = max(maxProfit,buy[i] + sell[i]);
   }
   return (maxProfit);
}