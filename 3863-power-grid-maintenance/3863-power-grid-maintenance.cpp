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
    vector<int> processQueries(int n, vector<vector<int>>& con, vector<vector<int>>& q) {  
        vector<vector<int>> adj(n);
        dsu ds(n);
        map<int,set<int>> mp;
        for(auto i:con){
            int u = i[0];
            int v = i[1];
            u--;
            v--;
            if(!ds.is_same_Group(u,v)){
                ds.unionbysize(u,v);
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        } 
        for(int i=0;i<n;i++){
            int up = ds.up(i);
            mp[up].insert(i);
        }
        vector<int> ans;
        for(auto i:q){
            int ty = i[0];
            int node = i[1];
            node--;
            int up = ds.up(node);
            if(ty==1){
                if(mp[up].count(node)){
                    ans.push_back(node+1);
                }
                else if(mp[up].empty()){
                    ans.push_back(-1);
                }
                else{
                    int u = *(mp[up].begin());
                    ans.push_back(u+1);
                }

            }
            else{
                if(mp[up].count(node)){
                    mp[up].erase(node);
                }
            }
        }
        return ans;

    }
};