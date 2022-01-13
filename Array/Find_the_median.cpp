class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    sort(v.begin(),v.end());
		    int n=v.size();
		    int ans;
		    if(n%2==0)
		    {
		        ans=(v[n/2]+v[(n/2)-1])/2;
		    }
		    else
		    {
		        ans=v[n/2];
		    }
		    return ans;
		}
};

//Method 2
int getMedian(int ar1[], int ar2[], int n)
{
    int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
}