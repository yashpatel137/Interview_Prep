class Solution{
    public:
    string findSubString(string str)
    {
        set <char> s(str.begin(), str.end());
        int n = s.size();
        s.clear();
        int l = 0, r = 0, ans = INT_MAX, idx1=0, idx2=0;
        map <char,int> mp;
        while(str[r] != '\0'){
            while(str[r] != '\0' && mp.size() != n){
                mp[str[r]]++;
                r += 1;
            }
            while(mp.size() == n){
                mp[str[l]]--;
                if(mp[str[l]] == 0)
                    mp.erase(str[l]);
                l += 1;
            }
            if(r-l < ans){
                ans = r-l;
                idx1 = l;
                idx2 = r;
            }
        }
        return str.substr(idx1-1, idx2-idx1+1);
    }
};