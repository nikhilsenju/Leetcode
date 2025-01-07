class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        sort(words.begin(),words.end(),[&](string&a , string&b){
            return a.size()<b.size();
        });
        vector<string> v;
        for(int i=0;i<n;i++){
            string chk= words[i];
            int f = 0;
            for(int j=i+1;j<n;j++){
                string s = words[j];
                for(int k = 0;k<s.size();k++){
                    for(int l=k;l<s.size();l++){
                        if(s.substr(k,l-k+1)==chk){
                            f=1;
                        }
                    }
                }
            }
            if(f){v.push_back(chk);}
        }
        return v;
        
    }

};