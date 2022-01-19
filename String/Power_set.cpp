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