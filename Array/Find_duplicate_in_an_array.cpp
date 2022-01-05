//Method 1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};

//Method 2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup=-1;
        for(int i=0;i<nums.size();i++)
        {
            int cur=abs(nums[i]);
            if(nums[cur]<0)
            {
                dup=cur;
                break;
            }
            nums[cur]=nums[cur]*-1;
        }
        for(auto num:nums)
        {
            num=abs(num);
        }
        return dup;
    }
};