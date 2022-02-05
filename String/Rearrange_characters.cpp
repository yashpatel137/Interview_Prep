class Solution
{
    public:
    string rearrangeString(string str)
    {
        map<char,int>m;
	    priority_queue<pair<int ,char>>pq;
	    for(auto &it:str)
	    {
	        m[it]++;
	    }
	    for(auto it:m)
	    {
	        pq.push({it.second,it.first});
	    }
	    string ans="";
	    while(!pq.empty())
	    {
	        pair<int,char>p1,p2;
	        p1=pq.top();
	        pq.pop();
	        p1.first--;
	        ans+=p1.second;
	        if(pq.size()>0)
	        {
	            p2=pq.top();
	            pq.pop();
	            ans+=p2.second;
	            p2.first--;
	        }
	        if(p1.first!=0)
	        {
	            pq.push(p1);
	        }
	        if(p2.first!=0)
	        {
	            pq.push(p2);
	        }
	    }
	    for(int i=0;i<ans.size()-1;i++)
	    {
	        if(ans[i]==ans[i+1])
	        {
	            return "-1";
	        }
	    }
	    return ans;
    }
    
};