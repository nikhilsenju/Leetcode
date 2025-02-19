class Solution {
public:
    void f(string &curr, string &s,int n,vector<string>&v){
        if(curr.size()>=n){
            v.push_back(curr);
            return;
        }
        for(int i=0;i<3;i++){
            if(curr.size()==0||s[i]!=curr.back()){
                curr.push_back(s[i]);
                f(curr,s,n,v);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        string s = "abc";
        vector<string> v;
        string curr;
        f(curr,s,n,v);
        if(v.size()>=k){
            return v[k-1];
        }
        return "";

    }
};