long long sumOfMaxAndMin(vector<int> &nums, int n, int k) 
{
	long long sum=0;
	int i=0;
	deque<int> mn,mx;
	for(i=0;i<k;i++)
	{
		while(!mn.empty() && nums[mn.back()]>=nums[i])
		{
			mn.pop_back();
		}
		while(!mx.empty() && nums[mx.back()]<=nums[i])
		{
			mx.pop_back();
		}
		mn.push_back(i);
		mx.push_back(i);
	}
	for(;i<n;i++)
	{
		sum+=nums[mn.front()]+nums[mx.front()];
		while(!mn.empty() && mn.front()<=i-k)
		{
			mn.pop_front();
		}
		while(!mx.empty() && mx.front()<=i-k)
		{
			mx.pop_front();
		}
		while(!mn.empty() && nums[mn.back()]>=nums[i])
		{
			mn.pop_back();
		}
		while(!mx.empty() && nums[mx.back()]<=nums[i])
		{
			mx.pop_back();
		}
		mn.push_back(i);
		mx.push_back(i);
	}
	sum+=nums[mn.front()]+nums[mx.front()];
	return sum;
}
