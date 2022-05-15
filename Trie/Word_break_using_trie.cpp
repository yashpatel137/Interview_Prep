// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
struct Node
{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return links[ch-'a'];
    }
    void put(char ch, Node *node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch)
    {
        return links[ch-'a'];
    }
    bool getEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag=true;
    }
};
class Trie
{
    private:
        Node *root;
    public:
        Trie()
        {
            root=new Node();
        }
        void insert(string word)
        {
            Node *temp=root;
            for(int i=0;i<word.length();i++)
            {
                if(!temp->containsKey(word[i]))
                {
                    temp->put(word[i],new Node());
                }
                temp=temp->get(word[i]);
            }
            temp->setEnd();
        }
        bool search(string word)
        {
            Node *temp=root;
            for(int i=0;i<word.length();i++)
            {
                if(temp->containsKey(word[i]))
                {
                    temp=temp->get(word[i]);
                }
                else
                {
                    return false;
                }
            }
            return temp->getEnd();
        }
};
bool solve(string s,Trie trie)
{
    int size=s.size();
    if(size==0)
    {
        return true;
    }
    for(int i=0;i<size;i++)
    {
        if(trie.search(s.substr(0,i+1)) and solve(s.substr(i+1,size-i+1),trie))
        {
            return true;
        }
    }
    return false;
}
class Solution{
    public:
    int wordBreak(string A, vector<string> &B) 
    {
        Trie trie;
        for(auto it:B)
        {
            trie.insert(it);
        }
        return solve(A,trie);
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}
  // } Driver Code Ends