class dsu {
public:
    vector<long long> parent, size;
    long long Number_of_Nodes, Number_of_Groups, Max_Group;

    dsu(long long Number_of_Nodes) : Number_of_Nodes(Number_of_Nodes), Number_of_Groups(Number_of_Nodes), Max_Group(1) {
        parent.resize(Number_of_Nodes + 1);
        size.resize(Number_of_Nodes + 1, 1);
        for (long long i = 1; i <= Number_of_Nodes; ++i) {
            parent[i] = i;
        }
    }

    long long up(long long x) {
        if (parent[x] != x) {
            parent[x] = up(parent[x]);
        }
        return parent[x];
    }

    bool is_same_Group(long long x, long long y) {
        return up(x) == up(y);
    }

    void unionbysize(long long x, long long y) {
        long long leader1 = up(x);
        long long leader2 = up(y);
        if (leader1 != leader2) {
            Number_of_Groups--;
            if (size[leader1] < size[leader2]) {
                swap(leader1, leader2);
            }
            parent[leader2] = leader1;
            size[leader1] += size[leader2];
            Max_Group = max(Max_Group, size[leader1]);
        }
    }

    long long getsize(long long x) {
        return size[up(x)];
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string s) {
        dsu ds(26);
        for(int i=0;i<s1.size();i++){
            int u = s1[i]-'a';
            int v = s2[i]-'a';
            if(!ds.is_same_Group(u,v)){
                ds.unionbysize(u,v);
            }
        }
        map<int,set<int>>mp;
        for(int i=0;i<26;i++){
            char up = ds.up(i);
            mp[up].insert(i);
        }
        string ans;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            int u = ch-'a';
            int nch = *(mp[ds.up(u)].begin());
            ans.push_back(min(nch,u)+'a');
        }
        return ans;
        
    }
};