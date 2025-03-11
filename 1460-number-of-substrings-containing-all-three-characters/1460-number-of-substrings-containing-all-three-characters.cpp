class Solution {
public:
    bool isValid(vector<int>&v){
        return (v[0]>=1 && v[1]>=1 && v[2]>=1);
    }
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans =0;
        int i=0;
        int j=0;
        vector<int> v(3,0);
        while(i<n && j<n){
            v[s[j]-'a']++;
            while(isValid(v)){
                ans+=(n-j);
                v[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
        
    }
};