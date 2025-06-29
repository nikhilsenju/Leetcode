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
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        dsu ds(n);
        sort(edges.begin(),edges.end(),[&](vector<int>&a,vector<int>&b){
            if(a[3]!=b[3]){
                return a[3]>b[3];
            }
            if(a[2]!=b[2]){
                return a[2]>b[2];
            }
            return a<b;
        });
        int not_up = (n-1)-k;
        int ans = INT_MAX;
        bool isposs = true;
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            int must = i[3];
            int wt = i[2];
            if(must){
                if(ds.is_same_Group(u,v)){
                    isposs=false;
                    break;
                }
                ds.unionbysize(u,v);
                ans = min(ans,wt);
                not_up--;
            }
            else{
                if(!ds.is_same_Group(u,v)){
                    if(not_up>0){
                        ans = min(ans,wt);
                        not_up--;
                    }
                    else{
                        ans = min(ans,2*wt);
                    }
                    ds.unionbysize(u,v);
                }

            }
        }
        
        if(!isposs || ds.Number_of_Groups>1){
            return -1;
        }
        return ans;
    }
};

