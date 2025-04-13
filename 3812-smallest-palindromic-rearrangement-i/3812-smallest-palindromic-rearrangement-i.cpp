class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n==1){
            return s;
        }
        string tmp;
        int sz = (n+1)/2;
        if(n&1){
            sz--;
        }
        for(int i=0;i<sz;i++){
            tmp.push_back(s[i]);
        }
        sort(tmp.begin(),tmp.end());
        string tmp1 = tmp;
        if(n&1){
            tmp.push_back(s[sz]);
        }
        reverse(tmp1.begin(),tmp1.end());
        string ans = tmp+tmp1;
        return ans;

        
    }
};