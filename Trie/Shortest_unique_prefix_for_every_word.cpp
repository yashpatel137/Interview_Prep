struct Trie
{
    Trie *dict[26];
    int count;
    Trie()
    {
        count=0;
        for(int i=0;i<26;i++)
        {
            dict[i]=NULL;
        }
    }
};
class Solution
{
    public:
    vector<string>ans;
    Trie *root=new Trie();
    void make(string s)
    {
        Trie *temp=root;
        for(int i=0;i<s.length();i++)
        {
            if(temp->dict[s[i]-'a']==NULL)
            {
                temp->dict[s[i]-'a']=new Trie;
            }
            temp->dict[s[i]-'a']->count++;
            temp=temp->dict[s[i]-'a'];
        }
    }
    vector<string> findPrefixes(string arr[], int n)
    {
        for(int i=0;i<n;i++)
        {
            make(arr[i]);
        }
        for(int i=0;i<n;i++)
        {
            Trie *temp=root;
            for(int j=0;j<arr[i].size();j++)
            {
                temp=temp->dict[arr[i][j]-'a'];
                if(temp->count==1)
                {
                    ans.push_back(arr[i].substr(0,j+1));
                    break;
                }
            }
        }
        return ans;
    }
    
};