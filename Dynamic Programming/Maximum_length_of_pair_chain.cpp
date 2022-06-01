class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        if(pairs.size()==0)
            return 0;
        if(pairs.size()==1)
            return 1;
        sort(pairs.begin(),pairs.end());          
        vector<int>v(pairs.size(),0);
        v[0]=1;
        for(int i=1;i<pairs.size();i++)
        {
            v[i]=1;
            for(int j=0;j<i;j++)
            {
              if(pairs[i][0]>pairs[j][1])
              {
                  v[i]=max(v[i],v[j]+1);
              }
            }   
        }
        return v[pairs.size()-1];
    }
};