class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minl=INT_MAX;
        int j=0,ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=nums[i];
            if(ans>=target)
            {
                while(ans>=target)
                {
                    minl=min(minl,i-j+1);
                    ans-=nums[j++];
                }
            }
        }
        return minl==INT_MAX?0:minl;
    }
};

//Method 2
int smallestSubWithSum(int arr[], int n, int x)
    {
        int i=0, j=0, sum = arr[0], mini = INT_MAX;
       while(j<n) {
           if(sum <= x) {
               j++; 
               sum = sum + arr[j];
           }
           else if(sum > x) {
               mini = min(mini, j-i+1);
               sum = sum - arr[i];
               i++;
           }
       } 
       return mini;
    }
