import java.util.*;
class Solution {
    public int numOfStrings(String[] patterns, String word) {
        HashMap<String,Integer> mp = new HashMap<>();
        int n = patterns.length;
        int m = word.length();
          for(int i=0;i<m;i++){
            String tmp = "";
            for(int j=i;j<m;j++){
                tmp+=word.charAt(j);
                mp.put(tmp,mp.getOrDefault(tmp,0)+1);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            String tmp = patterns[i];
            if(mp.getOrDefault(tmp,0)>0){
                ans++;
            }
        }   

        return ans;
        
        
    }
}