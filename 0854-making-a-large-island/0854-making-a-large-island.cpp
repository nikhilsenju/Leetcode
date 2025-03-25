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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int c = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1){
                    c++;
                }
            }
        }
        if(c==0){
            return 1;
        }
        if(c==n*n){
            return n*n;
        }
        dsu ds(n*n+1);
        // connect the graph
        vector<int> dx= {-1,0,1,0};
        vector<int> dy= {0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int par = i*n+j;
                    for(int k=0;k<4;k++){
                        int nr = i+dx[k];
                        int nc = j+dy[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int child = nr*n+nc;
                            ds.unionbysize(par,child);
                        }
                    }

                }
            }
        }  
        int maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int par = i*n+j;
                    set<int> st;
                    int sz = 0;
                    for(int k=0;k<4;k++){
                        int nr = i+dx[k];
                        int nc = j+dy[k];
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                            int child = nr*n+nc;
                            st.insert(ds.up(child));

                        }
                    }
                    for(auto k:st){
                        sz+=ds.getsize(k);
                    }
                    sz++;
                    maxi=max(maxi,sz);

                }
            }
        }
        return maxi;      

        
    }
};