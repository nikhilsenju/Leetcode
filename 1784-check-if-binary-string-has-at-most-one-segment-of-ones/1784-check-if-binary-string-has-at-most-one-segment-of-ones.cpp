class Solution {
public:
    bool checkOnesSegment(string s) {
        int fl = 0;
        int cnt = 0;
        for(auto i:s){
            if(i=='1'){
                if(fl==0){
                    cnt++;
                }
                fl=1;
            }
            else{
                fl=0;
            }
        }
        return cnt<=1;
    }
};