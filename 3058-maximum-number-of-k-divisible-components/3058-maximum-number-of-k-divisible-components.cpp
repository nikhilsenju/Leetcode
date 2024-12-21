class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n+1);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = 0;
        vector<long long> v(n,0); 
        function<long long(int,int)>dfs = [&](int node , int parent){
            v[node]=0;
            for(auto it:adj[node]){
                if(it!=parent){
                    v[node]+=dfs(it,node);
                }
            }
            v[node]+=values[node];
            if(v[node]%k==0){ans++;return (long long)0;}
            return v[node];
        };
        dfs(0,-1);
        return ans;



        
    }
};