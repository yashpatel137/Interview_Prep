int deno[] = { 1, 2, 5, 10, 20,
               50, 100, 500, 1000 };
int n = sizeof(deno) / sizeof(deno[0]);
  
vector<int> findMin(int V)
{
    sort(deno, deno + n);
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) 
    {
        while (V >= deno[i]) 
	{
            V -= deno[i];
            ans.push_back(deno[i]);
        }
    }
	return ans;
}

//Method 2
class Solution{

	public:
	int minCoins(int coins[], int n, int v) 
	{ 
	    if(v==0)
	    {
	        return 0;
	    }
	    int count=INT_MAX;
	    for(int i=0;i<n;i++)
	    {
	        if(v>=coins[i])
	        {
	            int c=minCoins(coins,n,v-coins[i]);
	            if(c!=INT_MAX and c+1<count)
	            {
	                count=c+1;
	            }
	        }
	    }
	    return count;
	} 
	  
};

//Method 3
int findMinCoins(int coins[], int size,  int value)
{
    int i, count = 0;

    for(i = 0; i < size; i++)
    {
        //take as much from coins[i]
        while(value >= coins[i])
        {
            //after taking the coin, reduce the value.
            value -= coins[i];
            ans[count] = coins[i];
            count++;
        }
        if(value == 0)
            break;

    }

    return count;
}
