class Solution {
public:
    int possibleStringCount(string word) {
        int n = word.size();
        int ans = 1;
        char ch = word[0];
        int count = 0;
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                count++;
            }
            else{
                ans+=(count-1);
                count = 1;
                ch = word[i];
            }
        }
        ans+=(count-1);
        return ans;
    }
};