//Method 1
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string> vec;
		    int n=s.size();
		    int size=pow(2,n);
		    for(int i=1;i<size;i++)
		    {
		        string temp="";
		        for(int j=0;j<n;j++)
		        {
		            if(i&(1<<j))
		            {
		                temp+=s[j];
		            }
		        }
		        vec.push_back(temp);
		    }
		    sort(vec.begin(),vec.end());
		    return vec;
		}
};
//Method 2
class Solution{
	public:
	    void solve(string s,string &op,vector<string> &vec)
	    {
	        if(s.length()==0)
	        {
	            if(op.length()>0)
	            {
	                vec.push_back(op);
	            }
	            return;
	        }
	        string op1=op;
	        string op2=op;
	        op2+=s.substr(0,1);
	        s=s.substr(1);
	        solve(s,op1,vec);
	        solve(s,op2,vec);
	        return;
	    }
		vector<string> AllPossibleStrings(string s){
		    vector<string> vec;
		    string op="";
		    solve(s,op,vec);
		    sort(vec.begin(),vec.end());
		    return vec;
		}
};
