import java.util.*;
class DSU{
    int n;
    int[] parent;
    int[] size;
    DSU(int n){
        parent = new int[n+1];
        size = new int[n+1];
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int up(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=up(parent[x]);
    }
    void ubs(int x , int y){
        int upx = up(x);
        int upy = up(y);
        if(upx==upy){
            return;
        }
        if(size[upx]>=size[upy]){
            size[upx]+=size[upy];
            parent[upy]=upx;
        }
        else{
            size[upy]+=size[upx];
            parent[upx]=upy;
        }
    }
}
class Solution {
    public int minScore(int n, int[][] roads) {
        DSU ds = new DSU(n);
        int m = roads.length;
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<m;i++){
            int ui = roads[i][0];
            int vi = roads[i][1];
            int di = roads[i][2];
            ds.ubs(ui,vi);
        }
        int up1 = ds.up(1);
        int mini = Integer.MAX_VALUE;
        for(int i=0;i<m;i++){
            if(ds.up(roads[i][0])==up1){
                mini = Math.min(mini,roads[i][2]);
            }
        }
        return mini;
    }
}