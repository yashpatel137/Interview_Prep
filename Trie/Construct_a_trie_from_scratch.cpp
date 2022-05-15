#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) 
        {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}

void insert(struct TrieNode *root, string key)
{
    TrieNode *temp=root;
    for(int i=0;key[i]!='\0';i++)
    {
        if(temp->children[key[i]-'a']==NULL)
        {
            temp->children[key[i]-'a']=getNode();
        }
        temp=temp->children[key[i]-'a'];
    }
    temp->isLeaf=true;
}
bool search(struct TrieNode *root, string key) 
{
    TrieNode *temp=root;
    for(int i=0;key[i]!='\0';i++)
    {
        if(temp->children[key[i]-'a']==NULL)
        {
            return false;
        }
        temp=temp->children[key[i]-'a'];
    }
    return temp->isLeaf;
}