class Solution {
public:
    bool issub(string &rep,string &s,int k){
        string emp = "";
        while(k--){
            emp+=rep;
        }
        int i =0;
        int j =0;
        while(i<s.size() && j<emp.size()){
            if(s[i]==emp[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
    
        return j>=emp.size();
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        queue<string>q;
        q.push("");
        string ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(char ch = 'a';ch<='z';ch++){
                string tmp = it+ch;
                if(issub(tmp,s,k)){
                    q.push(tmp);
                    if(ans.size()<tmp.size() || tmp>ans){
                        ans = tmp;
                    }
                }
            }
        }
        return ans;
    }
};