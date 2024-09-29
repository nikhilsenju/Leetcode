class Solution {
public:
    char kthCharacter(int k) {
        int t=k;
        int c = 1;
        while(k){
            c++;k=k/2;
        }
        string ans="a";
        while(c){
            string tmp;
            for(auto i:ans){
                if(i=='z'){
                    tmp.push_back('a');
                }
                else{
                    char d=i;
                    d++;
                    tmp.push_back(d);
                }

            }
            ans+=tmp;
            c--;
        }
        return ans[t-1];
        
    }
};