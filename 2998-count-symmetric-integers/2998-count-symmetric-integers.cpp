class Solution {
public:
    int count(int num){
        string s = to_string(num);
        if(s.size()&1){return 0;}
        int a = 0;
        int tot = 0;
        for(int i=0;i<s.size();i++){
            tot+=s[i]-'0';
        }
        for(int i=0;i<s.size()/2;i++){
            a+=s[i]-'0';
        }
        return 2*a==tot;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low;i<=high;i++){
            ans+=count(i);
        }
        return ans;

        
    }
};