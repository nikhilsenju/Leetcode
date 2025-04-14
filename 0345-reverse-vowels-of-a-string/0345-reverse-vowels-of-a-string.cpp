class Solution {
public:
    string reverseVowels(string s) {
        int n = s.size();
        int i = 0;
        int j = n-1;
        set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        while(j>i){
            while(i<j && !st.count(s[i])){
                i++;
            }
            cout<<i<< " ";
            while(i<j && !st.count(s[j])){
                j--;
            }
            cout<<endl;
            cout<<j<<" ";
            if(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
            }
        }
        return s;
        
    }
};