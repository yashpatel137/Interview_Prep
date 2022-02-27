class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char,int>mp;
		    vector<char> vec;
		    string ans="";
		    int size=A.length();
		    for(int i=0;i<size;i++)
		    {
		        if(mp.find(A[i])!=mp.end())
		        {
		            auto it=find(vec.begin(),vec.end(),A[i]);
		            if(it!=vec.end())
		            {
		                vec.erase(it);
		            }
		        }
		        else
		        {
		            mp[A[i]]++;
		            vec.push_back(A[i]);
		        }
		        if(vec.size()==0)
		        {
		            ans+='#';
		        }
		        else
		        {
		            ans+=vec[0];
		        }
		    }
		    return ans;
		}

};