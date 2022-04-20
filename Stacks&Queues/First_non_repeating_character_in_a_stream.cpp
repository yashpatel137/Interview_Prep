//Method 1
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
//Method 2 using queue
class Solution {
	public:
		string FirstNonRepeating(string A){
		    queue<char>q;
		    vector<int> vec(26,0);
		    string ans="";
		    int size=A.length();
		    for(int i=0;i<size;i++)
		    {
		        vec[A[i]-'a']++;
		        if(vec[A[i]-'a']==1)
		        {
		            q.push(A[i]);
		        }
		        while(!q.empty() && vec[q.front()-'a']!=1)
		        {
		            q.pop();
		        }
		        if(q.empty())
		        {
		            ans+='#';
		        }
		        else
		        {
		            ans+=q.front();
		        }
		    }
		    return ans;
		}

};