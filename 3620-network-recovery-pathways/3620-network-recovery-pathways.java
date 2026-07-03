import java.util.*;

class Solution {
    static class Edge {
        int v;
        int wt;

        Edge(int v, int wt) {
            this.v = v;
            this.wt = wt;
        }
    }

    static class State implements Comparable<State> {
        long dis;
        int node;

        State(long dis, int node) {
            this.dis = dis;
            this.node = node;
        }

        @Override
        public int compareTo(State s) {
            return Long.compare(this.dis, s.dis);
        }
    }

    static ArrayList<Edge>[] adj;
    static int n;

    boolean isValid(int n, int mwt, long k) {
        long[] dist = new long[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        PriorityQueue<State> pq = new PriorityQueue<>();
        pq.offer(new State(0, 0));
        while (!pq.isEmpty()) {
            State s = pq.poll();
            long curdis = s.dis;
            int curnode = s.node;
            if (curdis > k) {
                return false;
            }
            if (curnode == n - 1) {
                return true;
            }
            if (curdis > dist[curnode]) {
                continue;
            }
            for (Edge e : adj[curnode]) {
                int ngh = e.v;
                int wt = e.wt;
                if (wt < mwt) {
                    continue;
                }
                if (curdis + wt < dist[ngh]) {
                    dist[ngh] = curdis + wt;
                    pq.offer(new State(dist[ngh], ngh));
                }
            }
        }
        return false;
    }

    public int findMaxPathScore(int[][] edges, boolean[] online, long k) {
        int m = edges.length;
        n = online.length;
        adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        int lo = Integer.MAX_VALUE;
        int hi = 0;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (!online[u] || !online[v]) {
                continue;
            }
            int wt = edges[i][2];
            lo = Math.min(lo, wt);
            hi = Math.max(hi, wt);
            adj[u].add(new Edge(v, wt));
        }
        if (!isValid(n, lo, k)) {
            return -1;
        }
        int ans = -1;
        while (hi >= lo) {
            int mid = lo + (hi - lo) / 2;
            if (isValid(n, mid, k)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;

    }
}