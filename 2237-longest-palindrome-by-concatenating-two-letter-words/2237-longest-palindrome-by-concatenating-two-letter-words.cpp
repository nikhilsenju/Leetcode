class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        int maxi = 0;
        int fl = 0;
        int ans = 0;
        for(auto i:mp){
            string s = i.first;
            int c = i.second;
            if(s[0]==s[1]){
                if(c&1){
                    if(!fl){
                        ans+=c*2;
                        fl=1;
                        continue;
                    }
                }
                ans+=(c/2)*4;
            }
            else{
                string rev;
                rev+=s[1];
                rev+=s[0];
                ans+=4*min(mp[rev],mp[s]);
                mp[rev]=0;
                mp[s]=0;
            }
        }
        return ans;

        
    }
};