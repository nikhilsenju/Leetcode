class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum = 0;
        int diff = 0;
        for(int i=0;i<=n;i++){
            sum+=(i%m==0?0:i);
            diff+=(i%m==0?i:0);
        }
        return sum-diff;
    }
};