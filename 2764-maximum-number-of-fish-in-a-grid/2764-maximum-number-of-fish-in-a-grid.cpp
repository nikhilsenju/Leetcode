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
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dsu ds(n*m+1);
        vector<int> row={-1,0,1,0};
        vector<int> col={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    int cur_node = i*m+j;
                    for(int k=0;k<4;k++){
                        int nr = i+row[k];
                        int nc = j+col[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<m){
                            if(grid[nr][nc]!=0){
                                int new_node = nr*m+nc;
                                ds.unionbysize(cur_node,new_node);
                            }
                        }

                    }

                }
            }
        }
        int maxi = 0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    mp[ds.up(i*m+j)]+=grid[i][j];
                }
            }
        }
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        return maxi;
        
    }
};