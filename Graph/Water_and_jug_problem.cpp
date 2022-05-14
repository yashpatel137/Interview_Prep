//Method 1 GCD
class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    bool canMeasureWater(int jug1, int jug2, int target) 
    {
        if(target>jug1+jug2)
        {
            return false;
        }
        if(target%gcd(jug1,jug2)==0)
        {
            return true;
        }
        return false;
    }
};

//Method 2
class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) 
    {
        int type[]={jug1,-jug1,jug2,-jug2};
        map<int,int> vis;
        queue<int>q;
        vis[0]=1;
        q.push(0);
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            if(tmp==target)
            {
                return true;
            }
            for(int i=0;i<4;i++)
            {
                int node=tmp+type[i];
                if(node==target)
                {
                    return true;
                }
                if(node<0 or node>jug1+jug2)
                {
                    continue;
                }
                if(vis[node]==0)
                {
                    q.push(node);
                    vis[node]=1;
                }
            }
        }
        return false;
    }
};