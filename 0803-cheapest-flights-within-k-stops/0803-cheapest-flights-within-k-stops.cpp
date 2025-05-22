class Solution {
public:
    struct Node{
        int stops;
        int cell;
        int weight;
        Node(int stops,int cell,int weight):stops(stops),cell(cell),weight(weight){}
    };
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:f){
            int u = i[0];
            int v = i[1];
            int wt = i[2];
            adj[u].push_back({v,wt});
        } 
        vector<vector<int>> dp(n,vector<int>(k+2,1e9));
        for(int i=0;i<=k;i++)
        {
            dp[src][i]=0;
        }
        queue<Node>q;
        q.push(Node(0,src,0));
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.stops;
            int cell = it.cell;
            int weight = it.weight;
            if(stops>k){
                continue;
            }
            for(auto j:adj[cell]){
                int ngh = j.first;
                int wt = j.second;
                if(dp[ngh][stops+1]>dp[cell][stops]+wt){
                    dp[ngh][stops+1]=dp[cell][stops]+wt;
                    q.push(Node(stops+1,ngh,dp[ngh][stops+1]));
                }
            }
        }
        int mini = *min_element(dp[dst].begin(),dp[dst].end());
        return mini==1e9?-1:mini;
        
    }
};