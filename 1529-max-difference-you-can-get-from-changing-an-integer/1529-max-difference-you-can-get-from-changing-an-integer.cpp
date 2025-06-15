class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        int fl = 1;
        for(int i=0;i<n;i++){
            if(s[i]!=s[0]){
                fl=0;
                break;
            }
        }
        if(fl){
            string ans(n,'8');
            return stoi(ans);
        }
        char ch1 = '.';
        char ch2 = '.';
        for(auto i:s){
            if(i!='9'){
                if(ch1=='.'){
                    ch1=i;
                }
            }
            if(i!='1' && i!='0'){
                if(ch2=='.'){
                    ch2=i;
                }
            }
        }
        string maxi;
        string mini;
        if(s[0]!='1'){
            ch2=s[0];
        }
        for(auto i:s){
            if(i==ch1){
                maxi.push_back('9');
            }
            else{
                maxi.push_back(i);
            }
            if(i==ch2){
                mini.push_back(ch2==s[0]?'1':'0');
            }
            else{
                mini.push_back(i);
            }
            
            
        }
        return stoi(maxi)-stoi(mini);
    }
};