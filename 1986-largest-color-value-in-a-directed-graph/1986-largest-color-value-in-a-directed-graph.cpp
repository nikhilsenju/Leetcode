class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> adj[n];
        for(auto i:edges){
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        vector<int> ind(n,0);
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                ind[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!ind[i]){
                q.push(i);
            }
        }
        int tot = 0;
        vector<vector<int>> dp(n,vector<int>(26,0));
        int maxi =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            tot++;
            dp[node][colors[node]-'a']++;
            maxi=max(maxi,dp[node][colors[node]-'a']);
            for(auto i:adj[node]){
                ind[i]--;
                if(ind[i]==0){
                    q.push(i);
                }
                 for(int j=0;j<26;j++){
                        dp[i][j]=max(dp[i][j],dp[node][j]);
                    }
            }
            
        }
        return tot==n?maxi:-1;


        
    }
};