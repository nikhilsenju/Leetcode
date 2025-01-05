class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> lazy(n+1,0);
        for(auto i:shifts){
            int x=1;
            if(i[2]==0){x=-1;}
            lazy[i[0]]+=x;
            lazy[i[1]+1]+=-x;
        }
        for(int i=1;i<=n;i++){
            lazy[i]+=lazy[i-1];
        }
        for(int i=0;i<=n;i++){
            cout<<lazy[i]<<" ";
        }
        string ans;
        for(int i=0;i<n;i++){
        char c = (s[i]-'a'+lazy[i]%26+26)%26+'a';
        ans.push_back(c);
        }
        return ans;



        
    }
};