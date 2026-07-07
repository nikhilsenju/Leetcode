import java.util.*;
class Solution {
    public long sumAndMultiply(int n) {
        String s = n+"";
        String ns ="";
        int sum = 0;
        for(int i=0;i<s.length();i++){
            char ch = s.charAt(i);
            if(ch!='0'){
                ns+=ch;
                sum+=ch-'0';
            }
        }
        if(ns.isEmpty()){
            return 0;
        }
        long num = Integer.parseInt(ns);
        long ans = num*sum;
        return ans;
        
    }
}