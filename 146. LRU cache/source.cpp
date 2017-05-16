class LRUCache{
public:
    map<int, pair<int, list<int>::iterator>>M;
    list<int>cache;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        // get also updates cache
        auto it = M.find(key);
        if(it == M.end())
        {
            return -1;
        }
        auto idx = M[key].second;
        int value = M[key].first;
        cache.erase(idx);
        cache.push_front(key);
        M[key] = make_pair(value, cache.begin());
        return value;
    }
    
    void set(int key, int value) {
        auto it = M.find(key);
        if(it != M.end())
        {
            //key exists
            auto idx = M[key].second;
            cache.erase(idx);
        }
        else
        {
            if(cache.size() >= cap)
            {
                //delete from cache as well as map
                auto idx = M.find(*(cache.rbegin()));
                M.erase(idx);
                cache.pop_back();
            }
        }
        cache.push_front(key);
        M[key] = make_pair(value, cache.begin());
    }
};