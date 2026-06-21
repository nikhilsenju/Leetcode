import java.util.*;

class Solution {
    public int shortestPath(int n, int[][] edges, String labels, int k) {

        List<int[]>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            adj[u].add(new int[]{v, w});
        }

        long[][] dist = new long[n][k + 2];

        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], Long.MAX_VALUE);
        }

        PriorityQueue<long[]> pq =
                new PriorityQueue<>((a, b) -> Long.compare(a[0], b[0]));

        dist[0][1] = 0;
        pq.offer(new long[]{0, 0, 1});

        while (!pq.isEmpty()) {
            long[] cur = pq.poll();

            long curd = cur[0];
            int curn = (int) cur[1];
            int curk = (int) cur[2];

            if (curd > dist[curn][curk]) {
                continue;
            }

            for (int[] edge : adj[curn]) {
                int ngh = edge[0];
                int wt = edge[1];

                int nextk;

                if (labels.charAt(curn) == labels.charAt(ngh)) {
                    nextk = curk + 1;
                } else {
                    nextk = 1;
                }

                if (nextk > k) {
                    continue;
                }

                long nd = curd + wt;

                if (nd < dist[ngh][nextk]) {
                    dist[ngh][nextk] = nd;
                    pq.offer(new long[]{nd, ngh, nextk});
                }
            }
        }

        long ans = Long.MAX_VALUE;

        for (int i = 1; i <= k; i++) {
            ans = Math.min(ans, dist[n - 1][i]);
        }

        return ans == Long.MAX_VALUE ? -1 : (int) ans;
    }
}

