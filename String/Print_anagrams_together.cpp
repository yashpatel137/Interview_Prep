class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        map<string,vector<string>> mp;
        vector<vector<string>> ans;
        for(auto x:string_list)
        {
            string temp=x;
            sort(x.begin(),x.end());
            mp[x].push_back(temp);
        }
        for(auto x:mp)
        {
            ans.push_back(x.second);
        }
        return ans;
    }
};