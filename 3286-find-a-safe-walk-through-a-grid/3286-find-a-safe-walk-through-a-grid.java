import java.util.*;
class Solution {
    static class State implements Comparable<State>{
        int d;
        int r;
        int c;
        State(int d ,int r ,int c){
            this.d = d;
            this.r = r;
            this.c = c;
        }
        @Override
        public int compareTo(State s){
            return Integer.compare(this.d, s.d);
        }
    }
    static int[] dr =  {1,0,-1,0};
    static int[] dc =  {0,-1,0,1};

    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int n = grid.size();
        int m = grid.get(0).size();
        int[][] dist = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dist[i][j]=Integer.MAX_VALUE;
            }
        }
        PriorityQueue<State> pq = new PriorityQueue<>();
        dist[0][0]=grid.get(0).get(0);
        pq.offer(new State(grid.get(0).get(0), 0, 0));
        while(!pq.isEmpty()){
            State s = pq.poll();
            int dis = s.d;
            int r = s.r;
            int c = s.c;
            System.out.println(dis+" "+r+" "+c);
            if(dist[r][c]!=dis){
                continue;
            }
            for(int i=0;i<4;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && dis+grid.get(nr).get(nc)<dist[nr][nc]){
                    dist[nr][nc]=dis+grid.get(nr).get(nc);
                    pq.offer(new State(dist[nr][nc], nr, nc));
                }
            }
        }
        System.out.print(dist[n-1][m-1]);
        return health>=dist[n-1][m-1]+1;
    }
}