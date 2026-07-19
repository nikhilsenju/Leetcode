class Solution {
    public String smallestSubsequence(String s) {
        int n = s.length();
        boolean[] vis = new boolean[26];
        int[] num = new int[26];
        for(int i=0;i<n;i++){
            num[s.charAt(i)-'a']++;
        }
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<n;i++){
            char ch = s.charAt(i);
            if(!vis[ch-'a']){
                while(sb.length()>0 && sb.charAt(sb.length()-1)>ch){
                    if(num[sb.charAt(sb.length()-1)-'a']>0){
                        vis[sb.charAt(sb.length()-1)-'a']=false;
                        sb.deleteCharAt(sb.length()-1);
                    }
                    else{
                        break;
                    }
                }
                vis[ch-'a']=true;
                sb.append(ch);
            }
            num[ch-'a']--;
        }
        return sb.toString();
    }
}