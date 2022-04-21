class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            if(i==k)ans.push_back(pq.top().first);
            pq.push({nums[i],i});
         
            if(k==n&&i==n-1)ans.push_back(pq.top().first);
            if(i<k)continue;
        
            while(pq.top().second<i-k+1){
               pq.pop(); 
            }
           ans.push_back(pq.top().first);
        }
        
        return ans;
    }
};