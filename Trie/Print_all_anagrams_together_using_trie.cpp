class Solution {
public:
    struct Trie
    {
        Trie *child[26];
        int isLeaf;
    };
    Trie *createTrieNode()
    {
        Trie *node=(Trie*)malloc(sizeof(Trie));
        for(int i=0;i<26;i++)
        {
            node->child[i]=NULL;
        }
        node->isLeaf=-1;
        return node;
    }
    int getID(Trie *node,string &tag,int &anId)
    {
        Trie *temp=node;
        for(int i=0;i<tag.length();i++)
        {
            if(temp->child[tag[i]-'a']==NULL)
            {
                temp->child[tag[i]-'a']=createTrieNode();
            }
            temp=temp->child[tag[i]-'a'];
        }
        if(temp->isLeaf==-1)
        {
            temp->isLeaf=++anId;
        }
        return temp->isLeaf;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> anagram;
        int anId=-1;
        Trie *obj=createTrieNode();
        string tag;
        int tagId;
        for(int i=0;i<strs.size();i++)
        {
            tag=strs[i];
            sort(tag.begin(),tag.end());
            tagId=getID(obj,tag,anId);
            if(tagId==anagram.size())
            {
                anagram.push_back(vector<string>(1,strs[i]));
            }
            else
            {
                anagram[tagId].push_back(strs[i]);
            }
        }
        return anagram;
    }
};