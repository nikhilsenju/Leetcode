class Solution {
public:
    int differenceOfSums(int n, int m) {
        int sum1 = n*(n+1)/2;
        int sum2 = m*(n/m)*(n/m+1);
        return sum1-sum2;
        
    }
};