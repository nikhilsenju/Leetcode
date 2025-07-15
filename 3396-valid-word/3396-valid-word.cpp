class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3){
            return false;
        }
        bool v = false;
        bool cons = false;
        set<char> st={'@','#','$'};
        set<char>vow={'a','e','i','o','u'};
        for(auto &i:word){
            if(i>='A' && i<='Z'){
                i=i+32;
            }
        }
        for(auto i:word){
            if(st.count(i)){
                return false;
            }
            if(vow.count(i)){
                v=true;
            }
            if(i>='a' && i<='z' ){
                if(!vow.count(i)){
                    cons = true;
                }
            }
            
        }
        return cons&&v;
    }
};