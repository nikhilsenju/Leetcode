typedef long long ll;
class Solution {
public:
    int minimizeXor(int num1, int num2) {
        ll count =0;
        for(int i=31;i>=0;i--){
            ll x = ((1LL)<<i);
            if(x&num2){
                count++;
            }
        }
        ll num=0;
        for(int i=31;i>=0;i--){
            ll x = ((1LL)<<i);
            if(x&num1 && count>0){
                num+=(x);
                count--;
            }
        }
        for(int i=0;i<=31;i++){
            ll x = ((1LL)<<i);
            if(!(x&num)){
                if(count>0){
                    num+=x;
                    count--;
                }
            }
            
        }
        return num;

        
    }
};