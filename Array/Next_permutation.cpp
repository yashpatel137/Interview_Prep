class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int point=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                point =i-1;
                break;
            }
        }
        if(point<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[point])
            {
                swap(nums[i],nums[point]);
                reverse(nums.begin()+point+1,nums.end());
                break;
            }
        }
    }
};