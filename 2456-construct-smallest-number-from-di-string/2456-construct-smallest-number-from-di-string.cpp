class Solution {
public:
    void f(int ind , int val, string &curr,string &s,vector<string>&v,vector<int>&used){
        if(ind>=s.size()){
            v.push_back(curr);
            return;
        }
        if(s[ind]=='I'){
            for(int j = val+1;j<=9;j++){
                if(!used[j]){
                    curr.push_back(j+'0');
                    used[j]=1;
                    f(ind+1,j,curr,s,v,used);
                    curr.pop_back();
                    used[j]=0;
                }
            }

        }
        else{
            for(int j = val-1;j>=1;j--){
                if(!used[j]){
                    curr.push_back(j+'0');
                    used[j]=1;
                    f(ind+1,j,curr,s,v,used);
                    curr.pop_back();
                    used[j]=0;
                }
            }

        }

    }
    string smallestNumber(string s) {
        int n  = s.size();
        vector<string> v;
        for(int i=1;i<=9;i++){
                vector<int> used(10,0);
                used[i]=1;
                string curr;
                curr.push_back(i+'0');
                f(0,i,curr,s,v,used);
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};