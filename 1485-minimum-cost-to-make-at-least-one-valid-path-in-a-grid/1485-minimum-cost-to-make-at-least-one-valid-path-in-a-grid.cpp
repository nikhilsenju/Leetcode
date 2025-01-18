class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>> pq;
        vector<vector<int>> mindis(n,vector<int>(m,INT_MAX));
        mindis[0][0]=0;
        pq.push({0,0,0});
        vector<int> r={-1,0,1,0};
        vector<int> c={0,1,0,-1};
        vector<int> s={4,1,3,2};
        while(!pq.empty()){
            auto it=pq.top();
            int currcost=it[0];
            int row=it[1];
            int col=it[2];
            pq.pop();
            if(mindis[row][col]!=currcost){continue;}
            for(int i=0;i<4;i++){
                int nr=r[i]+row;
                int nc=c[i]+col;
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(currcost+(s[i]!=grid[row][col]?1:0)<mindis[nr][nc]){
                        mindis[nr][nc]=currcost+(s[i]!=grid[row][col]?1:0);
                        pq.push({mindis[nr][nc],nr,nc});
                    }
                }
            }
            

        }
        return mindis[n-1][m-1];

        
    }
};