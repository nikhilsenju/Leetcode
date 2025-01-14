class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            set<int> st;
            int count=0;
            for(int j=0;j<=i;j++){
                st.insert(a[j]);
            }
            for(int j=0;j<=i;j++){
                if(st.count(b[j])){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
        
    }
};