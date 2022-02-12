class Solution {
public:
    bool canPlace(vector<int> &position, int size,int cows,int dist)
    {
        int prev=position[0];
        int cnt=1;
        for(int i=1;i<size;i++)
        {
            if((position[i]-prev)>=dist)
            {
                cnt++;
                prev=position[i];
            }
            if(cnt==cows)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        int ans;
        sort(position.begin(),position.end());
        int low=1,high=position[n-1]-position[0];
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(canPlace(position,n,m,mid))
            {
                ans=mid;
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
};