class DSU {
    int[] parent, size;
    int groups;

    DSU(int n) {
        parent = new int[n + 1];
        size = new int[n + 1];
        groups = n;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    boolean connected(int x, int y) {
        return find(x) == find(y);
    }

    void union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return;
        groups--;
        if (size[x] < size[y]) {
            int t = px;
            px = py;
            py = t;
        }
        size[px] += size[py];
        parent[py] = px;

    }
}

class Solution {
    public int maxStability(int n, int[][] edges, int k) {
        Arrays.sort(edges,(a,b)->{
            if(a[3]!=b[3]){
                return b[3]-a[3];
            }
            if(a[2]!=b[2]){
                return b[2]-a[2];
            }
            return 0;
        });
        DSU ds = new DSU(n);
        int not_up = n-1-k;
        int ans = Integer.MAX_VALUE;
        for(int[] e:edges){
            int u = e[0];
            int v = e[1];
            int s = e[2];
            int m = e[3];
            if(m==1){
                if(ds.connected(u,v)){
                    return -1;
                }
                not_up--;
                ds.union(u,v);
                ans =Math.min(ans,s);
            }
            else{
                if(!ds.connected(u,v)){
                    if(not_up>0){
                        ans = Math.min(ans,s);
                        not_up--;
                    }
                    else{
                        ans = Math.min(ans,2*s);
                    }
                    ds.union(u,v);
                }

            }
        }
        return ds.groups>1? -1:ans;
    }
}