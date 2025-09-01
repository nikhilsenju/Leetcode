class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<int> hash(256,0);
        while(i<n && j<n){
            hash[s[j]]++;
            //while there are more than one freq of a particular char
            while(i<=j && hash[s[j]]>1){
                //reduce the length of the window
                hash[s[i]]--;
                i++;
            }
            ans = max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};