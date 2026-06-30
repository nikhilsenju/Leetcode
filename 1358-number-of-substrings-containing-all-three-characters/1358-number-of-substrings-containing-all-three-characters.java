import java.util.*;
class Solution {
    static boolean good(int[] hash){
        if(hash[0]>0 && hash[1]>0 && hash[2]>0){
            return true;
        }
        return false;
    }
    public int numberOfSubstrings(String s) {
        int n = s.length();
        int[] hash = new int[3];
        int i =0;
        int j =0;
        int ans = 0;
        while(i<n && j<n){
            //add
            hash[s.charAt(j)-'a']+=1;
            while(good(hash)){
                ans+=(n-j);
                hash[s.charAt(i)-'a']-=1;
                i++;
            }
            j++;
        }
        return ans;

    }
}