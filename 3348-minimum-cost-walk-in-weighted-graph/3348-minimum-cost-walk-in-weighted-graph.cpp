
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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        dsu ds(n);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            if(!ds.is_same_Group(u,v)){
                ds.unionbysize(u,v);
            }

        }
        map<int,int> mp;
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int wt = i[2]; 
            int dup = ds.up(u);
            if(mp.find(dup)==mp.end()){
                mp[dup]=wt;
            }      
            else{
                mp[dup]=mp[dup]&wt;
            }

        }
        vector<int> ans;
        for(auto i:query){
            int u = i[0];
            int v = i[1];
            if(ds.is_same_Group(u,v)){
                int dup = ds.up(u);
                ans.push_back(mp[dup]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;

        
        
    }
};