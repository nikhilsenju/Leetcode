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
        vector<int> freq(26);
        for(auto i:s){
            freq[i-'a']++;
        } 
        for(int i=0;i<26;i++){
            if(freq[i]<k){
                freq[i]=0;
            }
            else{
                freq[i]=freq[i]/k;
            }
        }
        queue<string>q;
        q.push("");
        string ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            for(char ch = 'z';ch>='a';ch--){
                if(freq[ch-'a']==0){continue;}
                string tmp = it+ch;
                if(issub(tmp,s,k)){
                    q.push(tmp);
                    if(ans.size()<tmp.size()){
                        ans = tmp;
                    }
                }
            }
        }
        return ans;
    }
};