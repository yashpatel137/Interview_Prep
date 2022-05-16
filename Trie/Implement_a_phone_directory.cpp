class Solution
{
public:
    struct Node
    {
        Node *links[26]={NULL};
        vector<string> v;
        bool containsKey(char ch)
        {
            return links[ch-'a']!=NULL;
        }
        Node *getKey(char ch)
        {
            return links[ch-'a'];
        }
        void put(char ch,Node *node)
        {
            links[ch-'a']=node;
        }
        void insertString(string str)
        {
            v.push_back(str);
        }
        vector<string> getV()
        {
            return v;
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
            Node *node=root;
            for(int i=0;i<word.length();i++)
            {
                if(node->links[word[i]-'a']==NULL)
                {
                    node->put(word[i],new Node());
                }
                node=node->getKey(word[i]);
                node->insertString(word);
            }
        }
        vector<string> getString(string word)
        {
            Node *node=root;
            for(int i=0;i<word.length();i++)
            {
                if(node->links[word[i]-'a']==NULL)
                {
                    return vector<string>{"0"};
                }
                node=node->getKey(word[i]);
            }
            return node->getV();
        }
    };
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        Trie trie;
        set<string>st;
        for(int i=0;i<n;i++)
        {
            st.insert(contact[i]);
        }
        set<string>::iterator it;
        for(it=st.begin();it!=st.end();it++)
        {
            trie.insert(*it);
        }
        vector<vector<string>> ans;
        string temp{};
        for(int i=0;i<s.length();i++)
        {
            temp+=s[i];
            vector<string> v=trie.getString(temp);
            ans.push_back(v);
        }
        return ans;
    }
};