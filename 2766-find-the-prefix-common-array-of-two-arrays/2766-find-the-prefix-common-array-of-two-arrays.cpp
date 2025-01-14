class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans;
        vector<int> freq(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            freq[a[i]]++;
            if(freq[a[i]]==2){cnt++;}
            freq[b[i]]++;
            if(freq[b[i]]==2){
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};