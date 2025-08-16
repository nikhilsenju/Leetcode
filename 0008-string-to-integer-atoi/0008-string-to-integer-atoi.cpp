class Solution {
public:
    string solve(string &s){
        int n = s.size();
        int i = 0;
        while(i<n && s[i]==' '){
            i++;
        }
        return s.substr(i,n-i);
    }
    int myAtoi(string s) {
        string str = solve(s);
        int n = str.size();
        if(n==0){
            return 0;
        }
        int pos = 1;
        int i = 0;
        if(str[0]=='+'){
            pos = 1;
            i++;
        }
        else if(str[0]=='-'){
            pos = -1;
            i++;
        }
        long long res = 0;
        while(i<n &&  str[i]>='0' && str[i]<='9'){
            int digit = str[i]-'0';
            res=res*10+digit;
            if(res>INT_MAX){
                return (pos==1?INT_MAX:INT_MIN);

            }
            i++;
        }
        res*=pos;
        if(res>INT_MAX){
            return INT_MAX;
        }
        if(res<INT_MIN){
            return INT_MIN;
        }
        return (int)res;

    }
};