import java.util.*;
class Solution {
    static class Pair{
        char ch;
        int len;
        Pair(char ch,int len){
            this.ch = ch;
            this.len = len;
        }
    }
    public int maxActiveSectionsAfterTrade(String s) {
        int n = s.length();
        ArrayList<Pair> arr = new ArrayList<>();
        char ch = s.charAt(0);
        int len = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='1'){
                count++;
            }
        }
        for(int i=0;i<n;i++){
            if(ch==s.charAt(i)){
                len++;
            }
            else{
                Pair tmp = new Pair(ch,len);
                arr.add(tmp);
                ch = s.charAt(i);
                len = 1;
            }
        }
        Pair tmp = new Pair(ch,len);
        arr.add(tmp);
        int maxi = count;
        for(int i=1;i<arr.size()-1;i++){
            if(arr.get(i-1).ch=='0' && arr.get(i+1).ch=='0'){
                maxi = Math.max(maxi,count+arr.get(i-1).len+arr.get(i+1).len);
            }
        }
        return maxi;
    }
}