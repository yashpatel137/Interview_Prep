//Method 1
class LRUCache
{
    public:
    class node
    {
        public:
        int key;
        int value;
        node *prev;
        node *next;
        node(int key, int value)
        {
            this->key=key;
            this->value=value;
        }
    };
    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    int capacity;
    map<int, node*> mp;
    LRUCache(int cap)
    {
        capacity=cap;
        head->next=tail;
        tail->prev=head;
    }
    void add(node *temp)
    {
        node *img=head->next;
        head->next=temp;
        temp->prev=head;
        temp->next=img;
        img->prev=temp;
    }
    void dele(node *temp)
    {
        node *deln=temp->next;
        node *delp=temp->prev;
        deln->prev=delp;
        delp->next=deln;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)!=mp.end())
        {
            node *res=mp[key];
            mp.erase(key);
            int ans=res->value;
            dele(res);
            add(res);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            node *exist=mp[key];
            mp.erase(key);
            dele(exist);
        }
        if(mp.size()==capacity)
        {
            mp.erase(tail->prev->key);
            dele(tail->prev);
        }
        add(new node(key,value));
        mp[key]=head->next;
    }
};

//Method 2
class LRUCache
{
    private:

    public:
    //Constructor for initializing the cache capacity with the given value.
    list<pair<int,int>> l;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    int size;
    LRUCache(int cap)
    {
        size=cap;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        l.splice(l.begin(),l,mp[key]);
        return mp[key]->second;
    }
    
    //Function for storing key-value pair.
    void set(int key, int value)
    {
        if(mp.find(key)!=mp.end())
        {
            l.splice(l.begin(),l,mp[key]);
            mp[key]->second=value;
            return;
        }
        if(l.size()==size)
        {
            auto temp=l.back().first;
            l.pop_back();
            mp.erase(temp);
        }
        l.push_front({key,value});
        mp[key]=l.begin();
    }
};