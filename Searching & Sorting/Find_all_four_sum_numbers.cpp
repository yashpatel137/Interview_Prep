//Method 1
class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        if(n<4)
        {
            return ans;
        }
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[arr[i]+arr[j]].push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=k-arr[i]-arr[j];
                if(mp.find(k-sum)!=mp.end())
                {
                    for(auto it:mp[sum])
                    {
                        int k=it.first;
                        int l=it.second;
                        if(k>j)
                        {
                            if(!ans.empty() && ans.back()[0]==arr[i] && ans.back()[1]==arr[j] && ans.back()[2]==arr[k] && ans.back()[3]==arr[l])
                                continue;
                            vector<int> temp={arr[i],arr[j],arr[k],arr[l]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

//Method 2
class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > res;
        if (num.empty())
            return res;
        int n = num.size(); 
        sort(num.begin(),num.end());
    
        for (int i = 0; i < n; i++) {
        
            int target_3 = target - num[i];
        
            for (int j = i + 1; j < n; j++) {
            
                int target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = n - 1;
            
                while(front < back) {
                
                    int two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                }
                
                while(j + 1 < n && num[j + 1] == num[j]) ++j;
            }
        
            while (i + 1 < n && num[i + 1] == num[i]) ++i;
        
        }
    
        return res;
    }
};