class Solution {
public:
    string next(string &s){
        string tmp = s;
        int n = s.size();
        for(int i=0;i<n;i++){
            tmp+=((tmp[i]-'a'+1)%26+'a');
        }
        return tmp;

    }
    char kthCharacter(int k) {
        string org = "a";
        while(true){
            if(org.size()>=k){
                return org[k-1];
            }
            org = next(org);
        }
        return 'a';
    }
};