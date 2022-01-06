//Method 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        vector<int> temp=intervals[0];
        if(intervals.size()==0)
        {
            return ans;
        }
        for(auto it : intervals)
        {
            if(temp[1]>=it[0])
            {
                temp[1]=max(it[1],temp[1]);
            }
            else
            {
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

//Method 2
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto it:intervals)
        {
            if(ans.empty() || ans.back()[1]<it[0])
            {
                ans.push_back(it);
            }
            else
            {
                ans.back()[1]=max(it[1],ans.back()[1]);
            }
        }
        return ans;
    }
};