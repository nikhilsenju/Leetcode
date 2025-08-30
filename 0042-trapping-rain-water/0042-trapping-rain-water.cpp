class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int>pref(n,0);
        int maxi = 0;
        for(int i=0;i<n;i++){
            pref[i]=maxi;
            maxi = max(maxi,h[i]);
        }
        maxi = 0;
        vector<int>suff(n,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=maxi;
            maxi = max(maxi,h[i]);
        }
        int ans = 0;
        for(int i=1;i<n-1;i++){
            int maxh = min(pref[i],suff[i]);
            if(maxh>=h[i]){
                ans+=(maxh-h[i]);
            }
        }
        return ans;

    }
};