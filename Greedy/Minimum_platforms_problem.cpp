//Method 1
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    	vector<pair<int,int>> v;
    	for(int i=0;i<n;i++)
    	{
    	    v.push_back({arr[i],dep[i]});
    	}
    	sort(v.begin(),v.end());
    	for(int i=0;i<n;i++)
    	{
    	    pair<int,int>temp;
    	    if(!pq.empty())
    	    {
    	        temp=pq.top();
    	    }
    	    if(pq.empty()==true)
    	    {
    	        pq.push({v[i].second,v[i].first});
    	    }
    	    else if(v[i].first>temp.first && pq.size()>=1)
    	    {
    	        pq.pop();
    	        pq.push({v[i].second,v[i].first});
    	    }
    	    else
    	    {
    	        pq.push({v[i].second,v[i].first});
    	    }
    	}
    	return pq.size();
    }
};

//Method 2
class Solution{
    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int plat=1;
    	int i=0,j=1;
    	while(j<n)
    	{
    	    if(arr[j]<=dep[i])
    	    {
    	        plat++;
    	    }
    	    else
    	    {
    	        i++;
    	    }
    	    j++;
    	}
    	return plat;
    }
};