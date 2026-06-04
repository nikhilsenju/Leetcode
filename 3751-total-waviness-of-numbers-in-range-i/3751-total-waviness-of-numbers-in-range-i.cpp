class Solution {
public:
    int waviness(int num){
        string s = to_string(num);
        int n = s.size();
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            if(s[i]>s[i-1] && s[i]>s[i+1]){
                ans++;
            }
            else if(s[i]<s[i-1] && s[i]<s[i+1]){
                ans++;
            }
        }
        return ans;

    }
    int totalWaviness(int num1, int num2) {
        int tot = 0;
        for(int i = num1;i<=num2;i++){
            tot += waviness(i);
        }
        return tot;
    }
};