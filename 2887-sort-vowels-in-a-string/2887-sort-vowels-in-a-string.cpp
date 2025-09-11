class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        set<char> st= {'a','e','i','o','u','A','E','I','O','U'};
        vector<char>v;
        for(auto i:s){
            if(st.count(i)){
                v.push_back(i);
            }
        }
        sort(v.begin(),v.end());
        int j = 0;
        for(int i=0;i<n;i++){
            if(st.count(s[i])){
                s[i]=v[j++];
            }
        }
        return s;
    }
};