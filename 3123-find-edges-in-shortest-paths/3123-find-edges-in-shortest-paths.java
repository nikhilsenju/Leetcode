import java.util.*;

class Solution {

    static class Edge {
        int to;
        int wt;

        Edge(int to, int wt) {
            this.to = to;
            this.wt = wt;
        }
    }

    static class State implements Comparable<State> {
        int node;
        long dist;

        State(int node, long dist) {
            this.node = node;
            this.dist = dist;
        }

        @Override
        public int compareTo(State other) {
            return Long.compare(this.dist, other.dist);
        }
    }

    private void dijkstra(int src, ArrayList<Edge>[] adj, long[] dist) {
        Arrays.fill(dist, Long.MAX_VALUE);

        PriorityQueue<State> pq = new PriorityQueue<>();
        dist[src] = 0;
        pq.offer(new State(src, 0));

        while (!pq.isEmpty()) {
            State cur = pq.poll();

            if (cur.dist != dist[cur.node])
                continue;

            for (Edge e : adj[cur.node]) {
                if (dist[e.to] > cur.dist + e.wt) {
                    dist[e.to] = cur.dist + e.wt;
                    pq.offer(new State(e.to, dist[e.to]));
                }
            }
        }
    }

    public boolean[] findAnswer(int n, int[][] edges) {

        ArrayList<Edge>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++)
            adj[i] = new ArrayList<>();

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].add(new Edge(v, w));
            adj[v].add(new Edge(u, w));
        }

        long[] distFromStart = new long[n];
        long[] distFromEnd = new long[n];

        dijkstra(0, adj, distFromStart);
        dijkstra(n - 1, adj, distFromEnd);

        long shortest = distFromStart[n - 1];

        boolean[] ans = new boolean[edges.length];

        for (int i = 0; i < edges.length; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if ((distFromStart[u] != Long.MAX_VALUE &&
                 distFromEnd[v] != Long.MAX_VALUE &&
                 distFromStart[u] + w + distFromEnd[v] == shortest)
                ||
                (distFromStart[v] != Long.MAX_VALUE &&
                 distFromEnd[u] != Long.MAX_VALUE &&
                 distFromStart[v] + w + distFromEnd[u] == shortest)) {
                ans[i] = true;
            }
        }

        return ans;
    }
}