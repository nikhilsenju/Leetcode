class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& v, int k) {
        for(int i=0;i<k-1;i++){
            v.push_back(v[i]);
        }
        int n = v.size();
        int ans = 0;
        int l = 0;
        int r = 1;
        while(r<n){
            if(v[r]==v[r-1])
            {
                l=r;
                r++;
                continue;
            }
            r++;
            if(r-l<k){
                continue;
            }
            ans++;
            l++;
        


        }
        return ans;

        
    }
};