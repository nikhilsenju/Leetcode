class Solution {
public:
    int solve(string &s,int k,char ch){
        int i=0;
        int j=0;
        int n=s.size();
        int maxi=0;
        int c=0;
        while(i<n && j<n){
            if(ch!=s[j]){
                c++;
            }
            while(c>k){
                if(s[i]!=ch){
                    c--;
                }
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxi =0;
        for(char ch = 'A';ch<='Z';ch++){
            maxi = max(maxi,solve(s,k,ch));

        }
        return maxi;
      
        
    }
};