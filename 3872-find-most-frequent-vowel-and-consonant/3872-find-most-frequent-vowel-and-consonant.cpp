class Solution {
public:
    int maxFreqSum(string s) {
        set<char> st = {'a','e','i','o','u'};
        int maxvow=0;
        int maxcons=0;
        map<int,int> mp;
        for(auto i:s){
            mp[i]++;
        }
        for(auto i:mp){
            if(st.count(i.first)){
                maxvow = max(maxvow,i.second);
            }
            else{
                maxcons = max(maxcons,i.second);
            }
        }
        return maxcons+maxvow;
    }
};