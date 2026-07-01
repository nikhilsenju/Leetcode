class Solution {
   static int[] dr = {1,0,-1,0}; 
    static int[] dc = {0,-1,0,1};
    static class State{
        int dis;
        int r;
        int c;
        State(int dis,int r,int c){
            this.dis = dis;
            this.r = r;
            this.c = c;
        }
    }
    static boolean isValid(int sf , int[][] dist){
        if(sf>dist[0][0]){
            return false;
        }

        int n = dist.length;
        int[][] vis = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
            }
        }   
        vis[0][0]=1;     
        ArrayDeque<State> q = new ArrayDeque<>();
        q.offer(new State(sf,0,0));
        while(!q.isEmpty()){
            State st = q.poll();
            int curdis = st.dis;
            int r = st.r;
            int c = st.c;
            if(r == n-1 && c==n-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && vis[nr][nc]==0 && dist[nr][nc]>=curdis){
                    vis[nr][nc]=1;
                    q.offer(new State(curdis,nr,nc));
                }

            }

        }
        return false;

    }
    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int n = grid.size();
        ArrayDeque<State> q = new ArrayDeque<>();
        int[][] vis = new int[n][n];
        int[][] dis = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=0;
                dis[i][j]=Integer.MAX_VALUE;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid.get(i).get(j)==1){
                    vis[i][j]=1;
                    dis[i][j]=0;
                    q.offer(new State(0, i, j));
                }
            }
        }
        while(!q.isEmpty()){
            State st = q.poll();
            int curdis = st.dis;
            int r = st.r;
            int c = st.c;
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && dis[nr][nc]>curdis+1){
                    dis[nr][nc]=curdis+1;
                    q.offer(new State(dis[nr][nc],nr,nc));
                }
            }
        }
        int lo = 0;
        int hi = 2*n;
        int ans = 0;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            if(isValid(mid,dis)){
                ans = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
}