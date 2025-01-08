class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& w) {
        int n = w.size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if(w[j].size()>=w[i].size()){
                    if(w[j].substr(0,w[i].size())==w[i] && w[j].substr(w[j].size()-w[i].size(),w[i].size())==w[i]){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};