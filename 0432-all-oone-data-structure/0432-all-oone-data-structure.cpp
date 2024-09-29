class AllOne {
public:
    map<string, int> mp;
    multiset<pair<int, string>> ms;
    
    AllOne() { }

    void inc(string key) {
        if (mp.find(key) != mp.end()) {
            int c = mp[key];
            mp[key] = c + 1;
            ms.erase(ms.find({c, key}));
            ms.insert({c + 1, key});
        } else {
            mp[key] = 1;
            ms.insert({1, key});
        }
    }

    void dec(string key) {
        if (mp.find(key) != mp.end()) {
            int c = mp[key];
            ms.erase(ms.find({c, key}));
            if (c == 1) {
                mp.erase(key); // Remove from mp if value becomes 0
            } else {
                mp[key] = c - 1;
                ms.insert({c - 1, key});
            }
        }
    }

    string getMaxKey() {
        if (ms.size() == 0) {
            return "";
        }
        auto it = ms.end();
        it--;
        return it->second;  // Access the second part of the pair
    }

    string getMinKey() {
        if (ms.size() == 0) {
            return "";
        }
        auto it = ms.begin();
        return it->second;  // Access the second part of the pair
    }
};
