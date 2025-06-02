class Solution {
public:
    int candy(vector<int>& rat) {
        int n = rat.size();
        vector<int> ans(n,0);
        ans[0]=1;
        for(int i=1;i<n;i++){
            if(rat[i]>rat[i-1]){
                ans[i]=ans[i-1]+1;
            }
            else{
                ans[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(rat[i]>rat[i+1]){
                if(ans[i]<=ans[i+1]){
                    ans[i]=1+ans[i+1];
                }
            }
        }
        int val = 0;
        for(int i=0;i<n;i++){
            val+=ans[i];
        }
        return val;
        
    }
};