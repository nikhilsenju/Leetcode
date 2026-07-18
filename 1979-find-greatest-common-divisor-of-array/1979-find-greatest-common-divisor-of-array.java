class Solution {
    static int gcd(int a, int b){
        while(b!=0){
            int tmp = b;
            b=a%b;
            a=tmp;
        }
        return a;
    }
    public int findGCD(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        return gcd(nums[0],nums[n-1]);
    }
}