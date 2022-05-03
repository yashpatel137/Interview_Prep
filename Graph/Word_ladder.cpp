class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string> q;
        int wordSize=beginWord.size();
        unordered_set<string> word;
        for(int i=0;i<wordList.size();i++)
        {
            word.insert(wordList[i]);
        }
        if(word.find(endWord)==word.end())
        {
            return 0;
        }
        q.push(beginWord);
        int ans=0;
        while(!q.empty())
        {
            ans++;
            int qlen=q.size();
            for(int i=0;i<qlen;i++)
            {
                string s=q.front();
                q.pop();
                for(int j=0;j<wordSize;j++)
                {
                    char ch=s[j];
                    for(char ch='a';ch<='z';ch++)
                    {
                        s[j]=ch;
                        if(s==endWord)
                        {
                            return ans+1;
                        }
                        if(word.find(s)==word.end())
                        {
                            continue;
                        }
                        word.erase(s);
                        q.push(s);
                    }
                    s[j]=ch;
                }
            }
        }
        return 0;
    }
};