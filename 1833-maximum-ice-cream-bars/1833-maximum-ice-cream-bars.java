import java.util.*;
class Solution {
    public int maxIceCream(int[] costs, int coins) {
        Integer maxi = Integer.MIN_VALUE;
        int n = costs.length;
        for(int i=0;i<n;i++){
            maxi = Math.max(maxi,costs[i]);
        }
        int[] cnt = new int[maxi+1];
        for(int i=0;i<n;i++){
            cnt[costs[i]]++;
        }
        for(int i=1;i<=maxi;i++){
            cnt[i]+=cnt[i-1];
        }
        int []ans = new int[n];
        for(int i=n-1;i>=0;i--){
            ans[cnt[costs[i]]-1]=costs[i];
            cnt[costs[i]]--;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            if(coins>=ans[i]){
                coins-=ans[i];
                sum++;
            }
        }
        return sum;


    }
}