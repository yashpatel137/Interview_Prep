class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0) return -1;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        if(target<=nums[n-1])
        {
            return binSearch(nums,target,l,n-1);
        }
        else
        {
            return binSearch(nums,target,0,l-1);
        }
        
    }
    int binSearch(vector<int> &nums,int target,int l,int r)
    {
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(target==nums[mid])
            {
                return mid;
            }
            if(target<nums[mid])
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
            
        }
        return -1;
    }
};