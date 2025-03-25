class dsu {
public:
    vector<long long> parent, size;
    long long Number_of_Nodes, Number_of_Groups, Max_Group;

    dsu(long long Number_of_Nodes)
        : Number_of_Nodes(Number_of_Nodes), Number_of_Groups(Number_of_Nodes),
          Max_Group(1) {
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

    bool is_same_Group(long long x, long long y) { return up(x) == up(y); }

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

    long long getsize(long long x) { return size[up(x)]; }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& v) {
        int mr = 0;
        int mc = 0;
        for(auto i:v){
            mr = max(mr,i[0]);
            mc = max(mc,i[1]);
        }
        dsu ds(mr+mc+1);
        unordered_map<int,int> mp;
        int totnodes=0;
        for(auto i:v){
            int u = i[0];
            int v = i[1]+mr+1;
            ds.unionbysize(u,v);
            mp[u]=1;
            mp[v]=1;
        }
        int con =0;
        for(auto i:mp){
            if(ds.up(i.first)==i.first){
                con++;
            }
        }
        return v.size()-con;




        
    }
};