class Solution {
    static int gcd(int a,int b){
        int tmp1 = Math.max(a,b);
        int tmp2 = Math.min(a,b);
        a = tmp1;
        b = tmp2;
        while(b!=0){
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
    public int gcdOfOddEvenSums(int n) {
        int even = n*(n+1);
        int odd = n*n;
        return gcd(odd , even);
    }
}