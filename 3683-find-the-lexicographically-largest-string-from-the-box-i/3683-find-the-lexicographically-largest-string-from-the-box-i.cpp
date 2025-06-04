class Solution {
public:
    string answerString(string word, int num) {
        int n = word.size();
        if(num==1){
            return word;
        }
        vector<int> v(26,0);
        for(auto i:word){
            v[i-'a']++;
        }
        char c = '.';
        for(int i=25;i>=0;i--){
            if(v[i]!=0){
                c=i+'a';
                break;
            }
        }
        string s="";
        int x = n-num+1;
        for(int i=0;i<n;i++){
            if(word[i]==c){
                int r = n-i;
                string cur = word.substr(i,min(r,x));
                if(cur>s){
                    s=cur;
                }
            }
        }
        return s;

    }
};