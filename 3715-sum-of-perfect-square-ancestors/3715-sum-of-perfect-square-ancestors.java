import java.util.*;
class Solution {
    static int MAX = 100005;
    static int[] kernel;
    static int[] spf;
    static ArrayList<Integer>[]adj;
    static int[] mp;
    static long ans = 0;
    static int[] vis;
    static public void createspf(){
        spf = new int[MAX+1];
        for(int i=0;i<=MAX;i++){
            spf[i]=i;
        }
        for(int i=2;i*i<=MAX;i++){
            if(spf[i]==i){
                for(int j=i*i;j<=MAX;j+=i){
                    if(spf[j]==j){
                        spf[j]=i;
                    }
                }
            }
        }
    }
    static public void createKernel(){
        kernel = new int[MAX+1];
        for(int i=1;i<=MAX;i++){
            int val = i;
            int k = 1;
            while(val>1){
                int cnt = 0;
                int p = spf[val];
                while(val%p==0){
                    val/=p;
                    cnt++;
                }
                if(cnt%2==1){
                    k*=p;
                }
            }
            kernel[i]=k;
        }
    }
    static public void dfs(int node,int[] nums){
        vis[node]=1;
        int k = kernel[nums[node]];
        ans+=mp[k];
        mp[k]++;
        for(int ngh :adj[node]){
            if(vis[ngh]==0){
                dfs(ngh,nums);
            }
        }
        mp[k]--;
    }
    public long sumOfAncestors(int n, int[][] edges, int[] nums) {
        ans=0;
        createspf();
        createKernel();
        adj = new ArrayList[n+1];
        int m = edges.length;
        for(int i=0;i<n;i++){
            adj[i] = new ArrayList<>();
        }
        for(int i=0;i<m;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].add(v);
            adj[v].add(u);
        }
        mp = new int[MAX+1];
        vis = new int[MAX+1];
        dfs(0,nums);
        return ans;

        
    }
}