

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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> ind(n);
        dsu ds(n);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            ind[u]++;ind[v]++;
            if(!ds.is_same_Group(u,v)){
                ds.unionbysize(u,v);
            }
        }
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            int dup = ds.up(i);
            mp[dup].push_back(i);
        }
        int count = 0;
        for(auto i:mp){
            int ct = i.second.size();
            bool fl = false;
            for(auto j:i.second){
                if(ind[j]!=ct-1){
                    fl=true;
                    break;
                }
            }
            if(!fl){
                count++;
            }
        }
        return count;

        
    }
};