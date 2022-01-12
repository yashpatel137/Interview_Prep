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