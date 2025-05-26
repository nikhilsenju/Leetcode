class Solution {
public:

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans = 0;
        function<long long(int,int)>dfs=[&](int node ,int par){
            long long sum = 0;
            for(auto i:adj[node]){
                if(i!=par){
                    sum+=dfs(i,node);
                }
            }
            sum+=values[node];
            if(sum%k==0){
                ans++;
                return (long long)0;
            }
            return sum;
        };
        dfs(0,-1);
        return ans;

        
    }
};