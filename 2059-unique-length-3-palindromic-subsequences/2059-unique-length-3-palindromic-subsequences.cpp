class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int> pre(26,0);
        vector<int> suff(26,0);
        for(int i=1;i<n;i++){
            suff[s[i]-'a']++;
        }
        pre[s[0]-'a']++;
        set<string> st;
        for(int i=1;i<n-1;i++){
            suff[s[i]-'a']--;
            for(int j=0;j<26;j++){
                if(pre[j]>0 && suff[j]>0){
                    string tmp;
                    tmp.push_back(j+'a');
                    tmp.push_back(s[i]);
                    st.insert(tmp);
                }
            }
            pre[s[i]-'a']++;

        }
        return st.size();

        
    }
};