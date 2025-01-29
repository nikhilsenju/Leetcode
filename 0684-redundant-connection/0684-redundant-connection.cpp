class Solution {
public:
    class dsu {
    public:
        vector<long long> parent, size;
        long long Number_of_Nodes, Number_of_Groups, Max_Group;

        dsu(long long Number_of_Nodes)
            : Number_of_Nodes(Number_of_Nodes),
              Number_of_Groups(Number_of_Nodes), Max_Group(1) {
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

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        dsu ds(n+1);
        vector<int> v;
        for(auto i:edges){
            if(ds.is_same_Group(i[0],i[1])){
                v={i[0],i[1]};
                break;
            }
            else{
                ds.unionbysize(i[0],i[1]);
            }
        }
        return v;


    }
};