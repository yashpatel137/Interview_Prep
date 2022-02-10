//Method 1
class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    unordered_map<int,int> mp;
	    int count=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        mp[nums[i]]=i;
	    }
	    vector<int> vec;
	    vec=nums;
	    sort(vec.begin(),vec.end());
	    for(int i=0;i<nums.size();i++)
	    {
	        if(nums[i]!=vec[i])
	        {
	            swap(nums[i],nums[mp[vec[i]]]);
	            swap(mp[nums[i]],mp[nums[mp[vec[i]]]]);
	            count++;
	        }
	    }
	    return count;
	}
};

//Method 2

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> vec;
	    int count=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        vec.push_back({nums[i],i});
	    }
	    sort(vec.begin(),vec.end());
	    for(int i=0;i<nums.size();i++)
	    {
	        while(vec[i].second!=i)
	        {
	            int tmp=vec[i].second;
	            swap(vec[i],vec[tmp]);
	            count++;
	        }
	    }
	    return count;
	}
};