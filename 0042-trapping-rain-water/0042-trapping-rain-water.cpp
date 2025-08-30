class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int left = 0;
        int right = n - 1;
        int maxleft = 0, maxright = 0,ans = 0;
        while(left<right){
            if(h[left]<=h[right]){
                if(h[left]>maxleft){
                    maxleft = h[left];
                }
                else{
                    ans+=(maxleft-h[left]);
                }
                left++;
            }
            else{
                if(h[right]>maxright){
                    maxright = h[right];
                }
                else{
                    ans+=maxright - h[right];
                }
                right--;
            }
        }
        return ans;
    }
};