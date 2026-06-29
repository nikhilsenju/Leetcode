import java.util.*;

class Solution {
    static class State {
        int first;
        int second;

        State(int first, int second) {
            this.first = first;
            this.second = second;
        }

        @Override
        public boolean equals(Object obj) {

            if (this == obj)
                return true;

            if (obj == null || getClass() != obj.getClass())
                return false;

            State other = (State) obj;

            return first == other.first &&
                    second == other.second;
        }

        @Override
        public int hashCode() {
            return Objects.hash(first, second);
        }
    }

    static class Pair implements Comparable<Pair> {
        int node;
        long d;
        int p;

        Pair(int node, long d, int p) {
            this.node = node;
            this.d = d;
            this.p = p;
        }

        @Override
        public int compareTo(Pair p) {
            if (this.d != p.d) {
                return Long.compare(this.d, p.d);
            }
            return -Long.compare(this.p, p.p);
        }
    }

    public long[] minTimeMaxPower(int n, int[][] edges, int power, int[] cost, int source, int target) {
        long[] ans = new long[2];
        ans[0] = -1;
        ans[1] = -1;
        if(source==target){
            ans[0]=0;
            ans[1]=power;
            return ans;
        }
        ArrayList<State>[] adj = new ArrayList[n];
        HashMap<State,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            adj[i]=new ArrayList<>();
        }
        int m = edges.length;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int t = edges[i][2];
            State st = new State(u, v);
            int dis = mp.getOrDefault(st, Integer.MAX_VALUE);
            mp.put(st, Math.min(dis, t));
        }
        for(Map.Entry<State,Integer> it : mp.entrySet()){
            int u = it.getKey().first;
            int v = it.getKey().second;
            int t = it.getValue();
            if(u==v){
                continue;
            }
            adj[u].add(new State(v, t));

        }
        long[][] dist = new long[n][1005];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 1005; j++) {
                dist[i][j] = Long.MAX_VALUE;
            }
        }
        dist[source][power]=0;
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.offer(new Pair(source, 0, power));
        while (!pq.isEmpty()) {
            Pair pp = pq.poll();
            int curnode = pp.node;
            long curdis = pp.d;
            int curpow = pp.p;
            if (dist[curnode][curpow] != curdis) {
                continue;
            }
            for (State s : adj[curnode]) {
                int ngh = s.first;
                int wt = s.second;
                if (curpow >= cost[curnode] && curdis + wt < dist[ngh][curpow - cost[curnode]]) {
                    dist[ngh][curpow - cost[curnode]] = curdis + wt;
                    pq.offer(new Pair(ngh, curdis + wt, curpow - cost[curnode]));
                }
            }
        }
        long mini = Long.MAX_VALUE;
        long maxi = Long.MIN_VALUE;
        for (int i = 0; i < 1005; i++) {
            if(dist[target][i]<mini){
                mini = dist[target][i];
                maxi = i;
            }
            else if(dist[target][i]==mini){
                maxi = Math.max(maxi,i);
            }
        }
        if (mini == Long.MAX_VALUE) {
            return ans;
        }
        ans[0] = mini;
        ans[1] = maxi;
        return ans;

    }
}