class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int c=0;
        vector<int> v;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){c++;}
        }
        if(c==2 || c==0) {
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1==s2){
                return true;
            }
            return false;
        }
        return false;
    }
};